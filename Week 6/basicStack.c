#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, int v) {
    stack_t *node = (stack_t *)malloc(sizeof (stack_t));
    node->data = v;
  //  node->next = NULL;

    node->next = s;
    s = node;
    return s;
}

void top(stack_t *s){
    if(s!=NULL) printf("%d\n",s->data);
    else printf("Stack is empty.\n");
}

stack_t *pop(stack_t *s) {
    if(s==NULL) return s;
    stack_t *tmp = (stack_t *)malloc(sizeof (stack_t));
    tmp = s;
    s = s->next;
    free(tmp);
    return s;
}

void empty(stack_t *s){
    if(s==NULL) printf("Stack is empty.\n");
    else printf("Stack is not empty.\n");
}

void size(stack_t *s){
    int ans=0;
    while(s!=NULL) {
        s=s->next;
        ans++;
    }
    printf("%d\n",ans);
}

int main(void) {
  stack_t *s = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        break;
      case 2:
        top(s);
        break;
      case 3:
        s = pop(s);
        break;
      case 4:
        empty(s);
        break;
      case 5:
        size(s);
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
3
5
3
5
*/
