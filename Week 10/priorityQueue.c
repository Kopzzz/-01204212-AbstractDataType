#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
  int *data;
  int last_index;
} heap_t;

void swap(int* a,int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

heap_t* init_heap(int m){
    heap_t* h = (heap_t*)malloc(sizeof(heap_t));
    h->data = (int)malloc(sizeof(int)*m);
    h->last_index=1;
    return h;
}

void insert(heap_t* h,int v){
    h->data[h->last_index] = v;
    h->last_index++;
    int index=h->last_index-1;
    while(1){
        int par=index/2;
        if(h->data[index] <= h->data[par] || index==1) break;
        swap(&h->data[index],&h->data[par]);
        index = par;
    }
}

void delete_max(heap_t* h){
    if(h->last_index == 1) return;
    h->data[1] = h->data[h->last_index-1];
    h->last_index--;
    int index=1;
    while(1){
        int child1=index*2;
        int child2=index*2+1;
        if (child1 >= h->last_index) break;
        if (child2 >= h->last_index){
            if(h->data[index] < h->data[child1]){
                swap(&h->data[index],&h->data[child1]);
                index = child1;
                continue;
            }
            break;
        }
        int max = (h->data[child1] > h->data[child2]) ? child1:child2;
        if(h->data[index] > h->data[max]) break;
        swap(&h->data[index],&h->data[max]);
        index = max;
    }
}

int find_max(heap_t* h){
    if (h->last_index==1) return -1;
    return h->data[1];
}

void update_key(heap_t* h,int o,int n){
    int i;
    for (i=1;i<h->last_index;i++) if(h->data[i]==o) break;

    h->data[i] = n;
    int index=i;
    while(1){
        int par=index/2;
        if(h->data[index] <= h->data[par] || index==1) break;
        swap(&h->data[index],&h->data[par]);
        index = par;
    }

    while(1){
        int child1=index*2;
        int child2=index*2+1;
        if (child1 >= h->last_index) break;
        if (child2 >= h->last_index){
            if(h->data[index] < h->data[child1]){
                swap(&h->data[index],&h->data[child1]);
                index = child1;
                continue;
            }
            break;
        }
        int max = (h->data[child1] > h->data[child2]) ? child1:child2;
        if(h->data[index] > h->data[max]) break;
        swap(&h->data[index],&h->data[max]);
        index = max;
    }
}

void bfs(heap_t* h){
    int i;
    for (i=1;i<h->last_index;i++){
        printf("%d ",h->data[i]);
    }
    printf("\n");
}

int main(void) {
  heap_t *max_heap = NULL;
  int    m, n, i;
  int    command, data;
  int    old_key, new_key;

  scanf("%d %d", &m, &n);
  max_heap = init_heap(m);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        insert(max_heap, data);
        break;
      case 2:
        delete_max(max_heap);
        break;
      case 3:
        printf("%d\n", find_max(max_heap));
        break;
      case 4:
        scanf("%d %d", &old_key, &new_key);
        update_key(max_heap, old_key,
                   new_key);
        break;
      case 5:
        bfs(max_heap);
        break;
    }
  }
  return 0;
}
