#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  float data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s,float v) {
    stack_t *node = (stack_t *)malloc(sizeof (stack_t));
    node->data = v;
  //  node->next = NULL;

    node->next = s;
    s = node;
    return s;
}

float top(stack_t *s){
    if(s!=NULL) return s->data;
    else return 0;
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
  int n,i;
  char a[1000005];
  scanf("%d %s",&n,&a);
  for (i=0; i<n; i++) {
       // printf("%c\n",a[i]);
        if(a[i]>='0' && a[i]<='9'){
            s = push(s,(float)a[i]-48);
          //  printf("111\n");
           // printf("%.2f\n",top(s));
        }
        else{
          //  printf("222\n");
            float tmp2=top(s);
            s = pop(s);
            float tmp1=top(s);
            s = pop(s);
            if(a[i]=='+') s = push(s,tmp1+tmp2);
            else if(a[i]=='-') s = push(s,tmp1-tmp2);
            else if(a[i]=='*') s = push(s,tmp1*tmp2);
            else if(a[i]=='/') s = push(s,tmp1/tmp2);
        }
      //  printf("%.2f\n",top(s));
    }
    printf("%.2f",top(s));

}
/*
>>> test case #1
5
12-3+
>>> test case #2
9
98*76+-5+
>>> test case #3
11
57+5*32*-2+
>>> test case #4
13
723*5+842/-*-
>>> test case #5
9
324*15-/+
*/
