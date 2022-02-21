#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  mod 131072
#define  TEXTSIZE 21

typedef struct item {
  char   *text;
  struct item *next;
} item_t;

typedef struct hash {
  item_t **table;
  int    size;
  int    hash_key;
} hash_t;

hash_t* init_hashtable(int m, int hash_key){
    hash_t* ht = (hash_t*)malloc(sizeof(hash_t));
    ht->size = m;
    ht->hash_key = hash_key;
    ht->table = (item_t**)malloc(sizeof(item_t*)*m);
    int i=0;
    for(i=0;i<m;i++)
        ht->table[i]=NULL;
    return ht;
}

unsigned int hash_map(char* str,int MUL,int m) {
    unsigned int hash_value = 0;
    int i = 0;
    for (i=1; i<=strlen(str); i++){
       // printf("%d * %d + %d = ",MUL,hash_value,str[i-1]);
        hash_value = MUL*hash_value + str[i-1];
      //  printf("%d\n",hash_value);
    }
  //  printf("%d mod %d = %d\n",hash_value,m,hash_value % m);
    return hash_value % m;
}

void insert(hash_t* ht,char* str){
    unsigned int index = hash_map(str,ht->hash_key,ht->size);
    item_t* node =(item_t *)malloc(sizeof (item_t));
    node->text = (char*)malloc(sizeof(char)*TEXTSIZE);

    strcpy(node->text,str);
    node->next = ht->table[index];
    ht->table[index] = node;
}

int search(hash_t* ht,char* str){
    unsigned int index = hash_map(str,ht->hash_key,ht->size);
    item_t* pos = ht->table[index];
    while(pos!=NULL){
        if(strcmp(pos->text,str)==0) return index;
        pos=pos->next;
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
/*211  20 93
1 fjdlo
2 fjdlo*/
