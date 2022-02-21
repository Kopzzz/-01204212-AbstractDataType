#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
  item_t *table;
  int    size;
  int    hash_key;
} hash_t;

hash_t* init_hashtable(int m, int hash_key){
    hash_t* ht = (hash_t*)malloc(sizeof(hash_t));
    ht->size = m;
    ht->hash_key = hash_key;
    ht->table = (item_t*)malloc(sizeof(item_t)*m);
    int i=0;
    for(i=0;i<m;i++)
        ht->table[i]=NULL;
    return ht;
}

unsigned int hash_map(char* str,int MUL,int m) {
    unsigned int hash_value = 0;
    int i = 0;
    for (i=1; i<=strlen(str); i++)
        hash_value = MUL*hash_value + str[i-1];
    return hash_value % m;
}

void insert(hash_t* ht,char* str){
    unsigned int index = hash_map(str,ht->hash_key,ht->size);
    unsigned int i;

    item_t node = (char*)malloc(sizeof(char)*TEXTSIZE);
    strcpy(node,str);

    for (i=0; i<ht->size; i++){
        int x = (index+(i + i*i)/2) % ht->size;
        if(ht->table[x]==NULL){
            ht->table[x] = node;
            break;
        }
    }
}

int search(hash_t* ht,char* str){
    unsigned int index = hash_map(str,ht->hash_key,ht->size);
    unsigned int i;

    for (i=0; i<ht->size; i++){
        int x = (index+(i + i*i)/2) % ht->size;
        if(ht->table[x] == NULL) return -1;
        if(strcmp(ht->table[x] , str) == 0){
            return x;
        }
    }
    return -1;
}


int main(void) {
  hash_t *hashtable = NULL;
  char   *text = NULL;
  int    m, n, i, hash_key;
  int    command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
      case 1:
        insert(hashtable, text);
        break;
      case 2:
        printf("%d\n", search(hashtable, text));
        break;
      }
  }
  return 0;
}

