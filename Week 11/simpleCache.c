#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  int mem_addr;
} cell_t;

typedef struct hash {
  cell_t *table;
  int    cache_size;
} hash_t;

typedef hash_t cache_t;
typedef int    memory_t;

memory_t *init_memory(int size) {
  memory_t *memory = (memory_t *)malloc(sizeof(memory_t)*size);
  int      i = 0;

  // Randomly assign integers to memory
  for (i=0; i<size; i++)
     memory[i] = rand();
  return memory;
}
/*
unsigned int hash_map(memory_t * mem,int size) {
    unsigned int hash_value = 0;
    int i = 0;
    for (i=1; i<=strlen(str); i++)
        hash_value = mem%size;
    return mem%size;
}*/

cache_t* init_cache(int size){
 /*   memory_t* mem = init_memory(size);
    int index = *mem%size;*/
    cache_t* ht = (cache_t*)malloc(sizeof(cache_t));
    ht->cache_size = size;
    ht->table = (cell_t*)malloc(sizeof(cell_t)*size);

    int i=0;
    for(i=0;i<size;i++)
        ht->table[i].mem_addr = -1;
    return ht;
}

void get_data(int addr,memory_t* mem,cache_t* ht){
   // memory_t* mem = init_memory(size);
    int index = addr % ht->cache_size;
    if(ht->table[index].mem_addr == -1){
        ht->table[index].mem_addr = addr;
        ht->table[index].data = mem[addr];
        printf("Load from memory\n");
        printf("Data: %d\n",ht->table[index].data);
    }
    else if(ht->table[index].data != mem[addr]){
        ht->table[index].mem_addr = addr;
        ht->table[index].data = mem[addr];
        printf("Index: %d is used\n",index);
        printf("Load from memory\n");
        printf("Data: %d\n",ht->table[index].data);
    }
    else{
        printf("Address %d is loaded\n",addr);
        printf("Data: %d\n",ht->table[index].data);
    }
}

int main(void) {
  memory_t *memory = NULL;
  cache_t  *cache = NULL;
  int memory_size, cache_size;
  int i, n, addr;

  scanf("%d %d %d", &memory_size, &cache_size, &n);
  memory = init_memory(memory_size);
  cache = init_cache(cache_size);

  for (i=0; i<n; i++) {
    printf("Load address: ");
    scanf("%d", &addr);
    get_data(addr, memory, cache);
  }
  return 0;
}
