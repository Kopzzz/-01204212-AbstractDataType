#include <stdio.h>
int main() {
    int m,p,n,i,j,count;
    scanf("%d %d %d",&m,&p,&n);
    char ar[m],sub[p];
    scanf("%s",&ar);
    scanf("%s",&sub);
   // printf("%s\n ",ar);
    for (i=0;i<m;i++){
        count=0;
        for(j=0;j<p;j++){
            if (ar[i+j]!=sub[j]){
                count++;
            }
            if (count>n || i+j>=m) {
                printf("%c",ar[i]);
                break;
            }
        }
        if (count<=n && i+p<=m) {
            printf("[");
            for (j=0;j<p;j++) {
                if (ar[i+j] == sub[j]) printf("%c",ar[i+j]);
                else printf("?");
            }
            printf("]");
            i+=p-1;
        }
    }
}
/*
18 3 0
acabababababcbabab
aba

18 3 1
acabababababcbabab
aba

18 3 1
acabababababcabbab
abc

15 4 2
AAAGTGTGTCTGATT
GTAT
*/

