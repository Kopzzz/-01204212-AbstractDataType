#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int dataI;
    double dataD;
    char dataC[11];
    int type;
    struct node *next;
}node_t;

node_t *append(node_t *startNode){
    int type; scanf("%d",&type);
    node_t *node = (node_t *)malloc(sizeof (node_t));

    if(type==0){
        int v; scanf("%d",&v);
        node->dataI = v;
        node->type = 0;
        node->next = NULL;
    }
    else if(type==1){
        double v; scanf("%lf",&v);
        node->dataD = v;
        node->type = 1;
        node->next = NULL;
    }
    else if(type==2){
        char v[11]; scanf("%s",&v);
        strcpy(node->dataC,v);
        node->type = 2;
        node->next = NULL;
    }

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
    while(n--) p = p->next;

    if(p->type==0) printf("%d\n",p->dataI);
    else if(p->type==1) printf("%.6f\n",p->dataD);
    else if(p->type==2) printf("%s\n",p->dataC);
}

void show(node_t *startNode) {
    node_t *p = startNode;
    while (p != NULL) {
        if(p->type==0) printf("%d ",p->dataI);
        else if(p->type==1) printf("%.6f ",p->dataD);
        else if(p->type==2) printf("%s ",p->dataC);
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
    return pre;
}

void show_reverse(node_t *startNode){
    startNode = reverse(startNode);
    show(startNode);
    startNode = reverse(startNode);
}

void insert(node_t *startNode){
    int pos,type; scanf("%d %d",&pos,&type);
    node_t *p = startNode;
    node_t *node = (node_t *)malloc(sizeof (node_t));

    while(pos--) p = p->next;
    node_t *tmp = p->next;
    p->next = node;


    if(type==0){
        int v; scanf("%d",&v);
        node->dataI = v;
        node->type = 0;
        node->next = tmp;
    }
    else if(type==1){
        double v; scanf("%lf",&v);
        node->dataD = v;
        node->type = 1;
        node->next = tmp;
    }
    else if(type==2){
        char v[11]; scanf("%s",&v);
        strcpy(node->dataC,v);
        node->type = 2;
        node->next = tmp;
    }
}

node_t *delete(node_t *startNode){
    int pos,i; scanf("%d",&pos);
    node_t *p = startNode;

    for(i=pos;i>1;i--) p = p->next;

    if (pos==0) {p = p->next; startNode=p;}
    else p->next = p->next->next;

    return startNode;
}

void change(node_t *startNode){
    int pos,type; scanf("%d %d",&pos,&type);
    node_t *p = startNode;
    while(pos--) p = p->next;

    if(type==0){
        int v; scanf("%d",&v);
        p->dataI = v;
        p->type = 0;
    }
    else if(type==1){
        double v; scanf("%lf",&v);
        p->dataD = v;
        p->type = 1;
    }
    else if(type==2){
        char v[11]; scanf("%s",&v);
        strcpy(p->dataC,v);
        p->type = 2;
    }
}

void is_empty(node_t *startNode){
    if(startNode==NULL) printf("Empty\n");
    else printf("Not Empty\n");
}

void length(node_t *startNode){
    node_t *p = startNode;
    int len=0;
    while(p!=NULL) {p = p->next; len++;}
    printf("%d\n",len);
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
                show_reverse(startNode);
                break;
            case 'I':
                insert(startNode);
                break;
            case 'D':
                startNode = delete(startNode);
                break;
            case 'C':
                change(startNode);
                break;
            case 'E':
                is_empty(startNode);
                break;
            case 'L':
                length(startNode);
                break;
            default:
                break;
        }
    }
}
/*
>>> test case #1
10
A 0 1
A 0 3
A 0 5
G 2
G 0
S
E
L
A 1 1.1
S

>>> test case #2
10
E
A 1 1
A 2 hello
A 0 5
S
R
D 1
S
D 0
G 0

>>> test case #3
11
L
A 2 hi
A 2 world
S
C 0 0 10
D 1
S
I 0 2 hello
S
C 1 1 5.5
R

>>> test case #4
10
A 2 I
A 2 am
C 1 2 You
C 0 2 hungry
I 0 2 are
R
I 1 2 guys
R
D 2
S
*/
