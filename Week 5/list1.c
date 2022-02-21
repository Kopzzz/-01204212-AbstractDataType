#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;

node_t *append(node_t *startNode){
    int v;
    scanf("%d",&v);

    node_t *node = (node_t *)malloc(sizeof (node_t));
    node->data = v;
    node->next = NULL;
    node_t *p = startNode;

    if(startNode == NULL) startNode = node;
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = node;
    }
    return startNode;
}

void get(node_t *startNode){
    int n;
    scanf("%d",&n);
    node_t *p = startNode;
    while(n--){
        p = p->next;
    }
    printf("%d\n",p->data);
}

void show(node_t *startNode) {
    node_t *p = startNode;
    while (p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

node_t *reverse(node_t *startNode){
    node_t *cur = startNode;
    node_t *pre=NULL,*next=NULL;
    while (cur != NULL){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    startNode = pre;
    return startNode;
}

node_t *cut(node_t *startNode){
    node_t *p = startNode;
    int s,e,i;
    scanf("%d %d",&s,&e);
    for(i=0;i<=e;i++){
        if(i==s) startNode = p;
        if(i==e) p->next=NULL;
        p = p->next;
    }
    return startNode;
}

int main(void){
    node_t *startNode;
    int n,i;
    char command;

    startNode = NULL;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf(" %c", &command);
        switch (command) {
            case 'A':
                startNode = append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            default:
                break;
        }
    }
}
/*
8
A 1
A 3
A 5
S
G 0
A 1
S
G 2

9
S
A 2
A 8
A 4
A 3
A 1
S
R
S

11
A 10
A 20
A 30
A 40
A 50
C 0 3
S
C 1 3
S
C 2 2
S

11
A 10
A 20
A 30
A 40
A 50
G 3
S
C 1 3
S
R
S
*/
