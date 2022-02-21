#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
    int value;
    int dep;
    struct tree *next_sibling;
    struct tree *first_child;
}tree_t;

typedef struct node{
  int          data;
  struct node *next;
} node_t;
typedef node_t queue_t;
typedef node_t stack_t;

queue_t *enqueue(queue_t *startNode, int v) {
    queue_t *node = (queue_t *)malloc(sizeof (queue_t));
    node->data = v;
    node->next = NULL;
    queue_t *p = startNode;

    if(startNode == NULL) startNode = node;
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = node;
    }
    return startNode;
}
queue_t *dequeue(queue_t *q) {
    if (q == NULL) printf("Queue is empty.\n");
    else {
      //  printf("%d\n",q->data);
        q = q->next;
    }
    return q;
}
int empty(node_t *n){
    if(n==NULL) return 1;
    else return 0;
}
stack_t *push(stack_t *s, int v) {
    stack_t *node = (stack_t *)malloc(sizeof (stack_t));
    node->data = v;
  //  node->next = NULL;

    node->next = s;
    s = node;
    return s;
}
stack_t *pop(stack_t *s) {
    if(s==NULL) return s;
    stack_t *tmp = (stack_t *)malloc(sizeof (stack_t));
    tmp = s;
    s = s->next;
    free(tmp);
    return s;
}
tree_t* travel(tree_t* t,int v){
    if (t==NULL) return t;
    if (t->value == v) return t;

    tree_t* pos = travel(t->first_child, v);
    if (pos != NULL) return pos;
    else return travel(t->next_sibling, v);
}
/*
tree_t* travelBefore(tree_t* t,int v,tree_t* pre){
    if (t==NULL) return NULL;
    if (t->value == v) return pre;

    tree_t* pos = travelBefore(t->first_child, v,t);
    if (pos != NULL)  return pos;
    else return travelBefore(t->next_sibling, v,t);
}
*/

tree_t* travelBefore(tree_t* t,int v,tree_t* pre){
    if (t==NULL) return NULL;
    if (t->value == v) return pre;

     pre = travelBefore(t->first_child, v,t);
    if (pre != NULL)  return pre;
    else return travelBefore(t->next_sibling, v,t);
}
stack_t* travelPath(tree_t* t,int v,stack_t* s){
    if (t==NULL) return t;
    if (t->value == v) {
        s = push(s,t->value);
        return s;
    }

    s = travelPath(t->first_child, v,s);
    if (!empty(s)){
        s = push(s,t->value);
        return s;
    }
    else return travelPath(t->next_sibling, v,s);
}

int travelDepth(tree_t* t,int v,int count){
    if (t==NULL) return -1;
    if (t->value == v) return count;

    int d = travelDepth(t->first_child, v,count+1);
    if (d != -1) return d;
    else return travelDepth(t->next_sibling, v,count);
}

void searchAllChild(tree_t* pos,int* p){
    *p+=1;
    if (pos->next_sibling != NULL) searchAllChild(pos->next_sibling,p);
}

stack_t* dfsAncestor(tree_t* t,int v,stack_t* s){
    if (t==NULL) return t;
    if (t->value == v) {
        s = push(s,t->value);
        return s;
    }

    s = dfsAncestor(t->first_child, v,s);
    if (!empty(s)){
        tree_t* pos = travel(t,s->data);
        if (t->dep != pos->dep) s = push(s,t->value);
        return s;
    }
    else return dfsAncestor(t->next_sibling, v,s);
}

tree_t* attach(tree_t* t,int parent,int child){//1
    tree_t* node = (tree_t *)malloc(sizeof (tree_t));
    node->value = child;
    node->next_sibling = NULL;
    node->first_child = NULL;
    if(parent == -1){
        node->dep=0;
        t = node;
        return t;
    }

    tree_t* pos = travel(t, parent);
    if (pos->first_child == NULL) {
        pos->first_child = node;
      //  printf("%d",pos->first_child->dep);
        pos->first_child->dep=travelDepth(t,child,0);
    }
    else {
        pos = pos->first_child;
        while (pos->next_sibling != NULL)
            pos = pos->next_sibling;
        pos->next_sibling = node;
        pos->next_sibling->dep = travelDepth(t,child,0);
    }
    return t;
}

tree_t* detach(tree_t* t,int v){//2
    tree_t* pos;
    if (t->first_child != NULL) pos = travelBefore(t->first_child,v,t);
    if (pos == NULL) pos = travelBefore(t->next_sibling,v,t);

    if (pos->first_child != NULL) if(pos->first_child->value == v){
        pos->first_child =pos->first_child->next_sibling;
    }
    if (pos->next_sibling != NULL) if(pos->next_sibling->value == v){
        pos->next_sibling =pos->next_sibling->next_sibling;
    }
    return t;
}

int search(tree_t* t,int v){//3
    if (travel(t,v) == NULL) return 0;
    else return 1;
}

int degree(tree_t* t,int v){//4
    int count=0;
    tree_t* pos = travel(t,v);

    if (pos->first_child != NULL) searchAllChild(pos->first_child,&count);
    return count;
}

int is_root(tree_t* t,int v){//5
    tree_t* pos = travel(t,v);
    if (pos->dep==0) return 1;
    else return 0;
}

int is_leaf(tree_t* t,int v){//6
    tree_t* pos = travel(t,v);
    if (pos->first_child == NULL) return 1;
    else return 0;
}

void siblings(tree_t* t,int v){//7
    tree_t* pos = travel(t,v);
    int d = pos->dep;
    if(d==0){
        while(pos!=NULL){
            if(pos->value!=v) printf("%d ",pos->value);
            pos = pos->next_sibling;
        }
        printf("\n");
        return;
    }
    int back=v;
    while(pos->dep==d){
        if (t->first_child != NULL) pos = travelBefore(t->first_child,back,t);
        if (pos == NULL) pos = travelBefore(t->next_sibling,back,t);
        back=pos->value;
    }
    pos = pos->first_child;
    while(pos!=NULL){
        if(pos->value!=v) printf("%d ",pos->value);
        pos = pos->next_sibling;
    }
    printf("\n");
}

int depth(tree_t* t,int v){//8
    tree_t* pos = travel(t,v);
    return pos->dep;
}

void print_path(tree_t* t,int start,int end){//9
    tree_t* pos = travel(t,start);
    stack_t* s=NULL;
    s = travelPath(pos,end,s);
    while(!empty(s)){
        printf("%d ",s->data);
        s=pop(s);
    }
    printf("\n");
}

int path_length(tree_t* t,int start,int end){//10
    tree_t* pos = travel(t,start);
    stack_t* s=NULL;
    s = travelPath(pos,end,s);
    int ans=0;
    while(s!=NULL) {
        s=s->next;
        ans++;
    }
    return ans;
}

void ancestor(tree_t* t,int v){//11
    stack_t* s=NULL;
    s = dfsAncestor(t,v,s);
    while(!empty(s)){
        printf("%d ",s->data);
        s=pop(s);
    }
    printf("\n");
}

void descendant(tree_t* t,int v){//12
    tree_t* pos = travel(t,v);
    bfs(pos);
}

void bfs(tree_t* t){//13
    queue_t *q = NULL;
    tree_t *pos = t;
    q = enqueue(q,pos->value);
    while(!empty(q)){
        pos=travel(t,q->data);
        printf("%d ",q->data);
        q = dequeue(q);
        if(pos->first_child != NULL){
            q = enqueue(q,pos->first_child->value);
            pos=pos->first_child;
            while(pos->next_sibling!=NULL){
                q = enqueue(q,pos->next_sibling->value);
                pos=pos->next_sibling;
                //q = enqueue(q,pos->value);
            }
        }
    }
    printf("\n");
}

tree_t *dfs(tree_t *t){//14
    if(t == NULL)
        return NULL;
    printf("%d ",t->value);
    tree_t *pos = dfs(t->first_child);
    if(pos != NULL)
        return pos;
    return dfs(t->next_sibling);
}

tree_t *dfsPrint(tree_t *t){
    int i;
    if(t == NULL)
        return NULL;

    for(i=0;i< t->dep;i++) printf("   ");
    printf("%d\n",t->value);
    tree_t *pos = dfsPrint(t->first_child);
    if(pos != NULL)
        return pos;
    return dfsPrint(t->next_sibling);
}

void print_tree(tree_t* t){//15
    dfsPrint(t);
}

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}
/*
15
1 -1 1
1 1 2
1 1 3
1 2 4
1 2 5
1 3 6
1 3 7
1 4 8
1 5 9
1 5 10
1 6 11
1 6 12
1 6 13
1 13 14
14
*/
