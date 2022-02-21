#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
  char         data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s,char v) {
    stack_t *node = (stack_t *)malloc(sizeof (stack_t));
    node->data = v;
  //  node->next = NULL;

    node->next = s;
    s = node;
    return s;
}

char top(stack_t *s){
    if(s!=NULL) return ("%c\n",s->data);
    else return NULL;
}

stack_t *pop(stack_t *s) {
    if(s==NULL) return s;
    stack_t *tmp = (stack_t *)malloc(sizeof (stack_t));
    tmp = s;
    s = s->next;
    free(tmp);
    return s;
}

int main(void) {
  stack_t *s = NULL;
  int n,i,ch=1;
  char a[1000005];
  scanf("%d %s",&n,&a);
  for (i=0; i<n; i++) {
    if(a[i]=='['||a[i]=='{'||a[i]=='(')
        s = push(s,a[i]);
    else{
        if(top(s)=='[' && a[i]==']' ||
           top(s)=='{' && a[i]=='}' ||
           top(s)=='(' && a[i]==')'){
            s = pop(s);
        }
        else {
           // printf("%c %c\n",top(s),a[i]);
            ch=0;
            break;
        }
    }
  }
  printf("%d",ch);
}
/*
>>> test case #1
8
()()[]{}
>>> test case #2
6
([()])
>>> test case #3
6
([)]{}
>>> test case #4
3
([)
*/
