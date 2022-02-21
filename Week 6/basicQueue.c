#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t queue_t;

queue_t *enqueue(queue_t *startNode, int v) {
    queue_t *node = (queue_t *)malloc(sizeof (queue_t));
    node->data = v;
    node->next = NULL;
    node_t *p = startNode;

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
        printf("%d\n",q->data);
        q = q->next;
    }
    return q;
}

void show(queue_t *q){
    if (q == NULL) printf("Queue is empty.");
    else while(q!=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}

void empty(queue_t *q){
    if(q==NULL) printf("Queue is empty.\n");
    else printf("Queue is not empty.\n");
}

void size(queue_t *q){
    int ans=0;
    while(q!=NULL) {
        q=q->next;
        ans++;
    }
    printf("%d\n",ans);
}

int main(void) {
  queue_t *q = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;
    }
  }
  return 0;
}
/*
>>> test case #1
9
1 2
2
1 4
2
1 6
1 8
1 10
5
4
>>> test case #2
7
5
4
2
3
1 8
1 10
5
>>> test case #3
9
1 2
1 2
1 2
5
3
2
5
3
5
*/
