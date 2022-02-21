#include <stdio.h>
#include <stdlib.h>
#include <week8.h>
//#include "week8.c"
#ifndef __bin_tree__
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif

int height(tree_t* t){
    if (t == NULL) return -1;
    int hl = height(t->left);
    int hr = height(t->right);
    return (hl>hr)? hl+1 : hr+1;
}
int size(tree_t *t)
{
    if (t==NULL) return 0;
    return size(t->left)+size(t->right)+1;
}
int is_full(tree_t* t){//1
    if(t->left==NULL && t->right==NULL) return 1;
    if(t->left==NULL && t->right!=NULL ||
       t->left!=NULL && t->right==NULL) return 0;

    int ans = is_full(t->left);
    if(!ans) return ans;
    else return is_full(t->right);
}

int chk_perfect(tree_t *t){
    if(t==NULL) return 1;
    int l=chk_perfect(t->left);
    int r=chk_perfect(t->right);
    if(l == r)
        return l+r;
    return 0;
}
int is_perfect(tree_t *t){//2
    if(chk_perfect(t)!=0)
        return 1;
    return 0;
}
int chk_complete(tree_t *t, int node, int all) {
  if (t == NULL) return 1;
  if (node > all) return 0;
  return (chk_complete(t->left,2*node, all) &&
          chk_complete(t->right,2*node+1, all));
}

int is_complete(tree_t *t){//3
    return chk_complete(t,1,size(t));
}

int is_degenerate(tree_t* t){//4
    if (t->left==NULL && t->right==NULL) return 1;
    if (t->left!=NULL && t->right!=NULL)return 0;

    if (t->left!=NULL) return is_degenerate(t->left);
    if (t->right!=NULL)return is_degenerate(t->right);
}

int is_skewed(tree_t* t){//5
    if (t==NULL) return 1;
    if (t->left!=NULL && t->right!=NULL) return 0;

    if(t->left!=NULL&&t->left->right!=NULL) return 0;
    if(t->right!=NULL&&t->right->left!=NULL) return 0;

    if (!is_skewed(t->left)) return 0;
    if (!is_skewed(t->right)) return 0;
    return 1;
}

int is_skewed(tree_t *t)
{
    if(t==NULL) return 1;
    if(t->left!=NULL&&t->right!=NULL) return 0;

    if(t->left!=NULL&&t->right==NULL) l = 1;
    if(l)
{
        if(t->right!=NULL)
            return 0;
        else
            return is_skewed(t->left);
    }
    else
    {
        if(t->left!=NULL)
            return 0;
        else
            return is_skewed(t->right);
    }
}
int main(void) {
  tree_t *t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }

  printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

  return 0;
}
