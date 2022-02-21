#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int    data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t bst_t;

bst_t* insert(bst_t* t,int v){
    bst_t* node = (bst_t*)malloc(sizeof(bst_t));
    node->data = v;
    node->left = NULL;
    node->right = NULL;

    if (t==NULL) {
        t=node;
        return t;
    }
    bst_t* pos = t;
    while(1){
        if(v<pos->data){
            if(pos->left!=NULL) pos=pos->left;
            else{
                pos->left = node;
                break;
            }
        }
        else{
            if(pos->right!=NULL) pos=pos->right;
            else{
                pos->right = node;
                break;
            }
        }
    }
    return t;
}

bst_t* delete(bst_t* t,int v){
    if (t == NULL) return t;

    if (v < t->data)
        t->left = delete(t->left, v);
    else if (v > t->data)
        t->right = delete(t->right, v);
    else {
        if (t->left == NULL) {//no or 1 child
            bst_t* tmp = t->right;
            free(t);
            return tmp;
        }
        else if (t->right == NULL) {//no or 1 child
            bst_t* tmp = t->left;
            free(t);
            return tmp;
        }
        //2 child
        int tmp = find_min(t->right);
        t->data = tmp;
        t->right = delete(t->right, tmp);
    }
    return t;
}

int find(bst_t* t,int v){
    if (t==NULL) return 0;
    bst_t* pos = t;
    while(pos->data!=v){
        if(v < pos->data) pos = pos->left;
        else pos = pos->right;
        if (pos==NULL) return 0;
    }
    return 1;
}

int find_min(bst_t* t){
    bst_t* pos = t;
    while(pos->left != NULL) pos = pos->left;
    return pos->data;
}

int find_max(bst_t* t){
    bst_t* pos = t;
    while(pos->right != NULL) pos = pos->right;
    return pos->data;
}

int main(void) {
  bst_t *t = NULL;
  int   n, i;
  int   command, data;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        t = insert(t, data);
        break;
      case 2:
        scanf("%d", &data);
        t = delete(t, data);
        break;
      case 3:
        scanf("%d", &data);
        printf("%d\n", find(t, data));
        break;
      case 4:
        printf("%d\n", find_min(t));
        break;
      case 5:
        printf("%d\n", find_max(t));
        break;
    }
  }
  return 0;
}
