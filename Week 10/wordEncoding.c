#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    char word[20];
    int freq;
    struct tree* left;
    struct tree* right;
}tree_t;

typedef struct heap {
    tree_t** data;
    int last_index;
} heap_t;

tree_t* init_tree(char w[20],int f){
    tree_t* node = (tree_t *)malloc(sizeof (tree_t));
    strcpy(node->word,w);
    node->freq = f;
    node->left = NULL;
    node->right = NULL;
    return node;
}

tree_t* combine(tree_t* l,tree_t* r){
    char c[20]="";
    tree_t* t=init_tree(c,l->freq + r->freq);
    t->left = l;
    t->right = r;
    return t;
}

void swap(tree_t** a,tree_t** b){
    tree_t* tmp=*a;
    *a=*b;
    *b=tmp;
}

heap_t* init_pq(int m){
    heap_t* h = (heap_t*)malloc(sizeof(heap_t));
    h->data = (tree_t**)malloc(sizeof(tree_t*)*m);
    h->last_index=1;
    return h;
}

void insert_pq(heap_t* h,tree_t* t){
    h->data[h->last_index] = t;
    h->last_index++;
    int index=h->last_index-1;
    while(1){
        int par=index/2;
        if(index==1 || h->data[index]->freq >= h->data[par]->freq) break;
        swap(&h->data[index],&h->data[par]);
        index = par;
    }
}

void delete_pq(heap_t* h){
    if(h->last_index == 1) return;
    h->data[1] = h->data[h->last_index-1];
    h->last_index--;
    int index=1;
    while(1){
        int child1=index*2;
        int child2=index*2+1;
        if (child1 >= h->last_index) break;
        if (child2 >= h->last_index){
            if(h->data[index]->freq > h->data[child1]->freq){
                swap(&h->data[index],&h->data[child1]);
                index = child1;
                continue;
            }
            break;
        }
        int min = (h->data[child1]->freq <= h->data[child2]->freq) ? child1:child2;
        if(h->data[index]->freq <= h->data[min]->freq) break;
        swap(&h->data[index],&h->data[min]);
        index = min;
    }
}

void dfs(tree_t* t,char arr[20]){
    if (t==NULL) return;
    if (t->left==NULL && t->right==NULL) printf("%s: %s\n",t->word,arr);
    char tmp1[20],tmp2[20];
    strcpy(tmp1,arr);
    strcpy(tmp2,arr);

    strcat(tmp1,"0");
    dfs(t->left,tmp1);
    strcat(tmp2,"1");
    dfs(t->right,tmp2);
}

int main(void) {
    heap_t* pq = NULL;
    int n,i,f;
    char w[20];
    char b[]={};
    scanf("%d",&n);
    pq = init_pq(1000);
    for(i=0;i<n;i++){
        scanf("%s %d",&w,&f);
        tree_t* t=init_tree(w,f);
        insert_pq(pq,t);
    }
    while(pq->last_index>2){
        tree_t* l = pq->data[1];
        delete_pq(pq);
        tree_t* r = pq->data[1];
        delete_pq(pq);

        tree_t* node = combine(l,r);

        insert_pq(pq,node);
    }
    char ar[20]="";
    dfs(pq->data[1],ar);

    return 0;
}

