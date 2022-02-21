#include <stdio.h>
#include <stdlib.h>
//#include <week9.h>
#include "week9.c"

#ifndef __avl_tree__
typedef struct node {
  int    data;
  int    height;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t avl_t;
#endif

int find_height(avl_t* t){
    if(t==NULL) return 0;
    else return t->height;
}
/*
int max(int a,int b){
	return (a>b)? a : b;
}
*/

avl_t* leftRotate(avl_t* l)
{
    avl_t* r = l->right;
    avl_t* tmp = r->left;

    r->left = l;
    l->right = tmp;

    int a = find_height(l->left);
    int b = find_height(l->right);
    l->height = ((a>b)? a:b)+1;

    a = find_height(r->left);
    b = find_height(r->right);
    r->height = ((a>b)? a:b)+1;

    return r;
}

avl_t* rightRotate(avl_t* r)
{
    avl_t* l = r->left;
    avl_t* tmp = l->right;

    l->right = r;
    r->left = tmp;

    int a = find_height(r->left);
    int b = find_height(r->right);
    r->height = ((a>b)? a:b)+1;

    a = find_height(l->left);
    b = find_height(l->right);
    l->height =((a>b)? a:b)+1;

    return l;
}

avl_t* insert(avl_t* t,int v){//1
    if (t==NULL) {
        avl_t* node = (avl_t*)malloc(sizeof(avl_t));
        node->data = v;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        t=node;
        return t;
    }
    if(v < t->data)
        t->left = insert(t->left,v);
    if(v > t->data)
        t->right = insert(t->right,v);

    int l = find_height(t->left);
    int r = find_height(t->right);
    t->height = ((l>r)? l:r)+1;

    int ch = l - r; //ch>1  l>r

    if(ch>1 && v<t->left->data) return rightRotate(t);
    if(ch>1 && v>t->left->data){
        t->left = leftRotate(t->left);
        return rightRotate(t);
    }
    if(ch<-1 && v>t->right->data) return leftRotate(t);
    if(ch<-1 && v<t->right->data){
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }
    return t;
}

int find_min(avl_t* t){
    avl_t* pos = t;
    while(pos->left != NULL) pos = pos->left;
    return pos->data;
}

avl_t* delete(avl_t* t,int v){//2
     if (t == NULL) return t;

    if (v < t->data)
        t->left = delete(t->left, v);
    else if (v > t->data)
        t->right = delete(t->right, v);
    else {
        if (t->left == NULL) {//no or 1 child
            avl_t* tmp = t->right;
            free(t);
            return tmp;
        }
        else if (t->right == NULL) {//no or 1 child
            avl_t* tmp = t->left;
            free(t);
            return tmp;
        }
         //2 child
        int tmp = find_min(t->right);
        t->data = tmp;
        t->right = delete(t->right, tmp);
    }

    int l = find_height(t->left);
    int r = find_height(t->right);
    t->height = ((l>r)? l:r)+1;
    int ch = l - r; //ch>1  l>r

    avl_t* L=t ;
    avl_t* R=t;
    L=L->left;
    R=R->right;

    if(ch>1 && find_height(L->left) > find_height(L->right)) return rightRotate(t);
    if(ch>1 && find_height(L->left) < find_height(L->right)){
        t->left = leftRotate(t->left);
        return rightRotate(t);
    }
    if(ch<-1 && find_height(R->right) > find_height(R->left)) return leftRotate(t);
    if(ch<-1 && find_height(R->right) < find_height(R->left)){
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }
    return t;
}

int main(void) {
  avl_t *t = NULL;
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
        print_tree(t);
        break;
    }
  }
  return 0;
}
