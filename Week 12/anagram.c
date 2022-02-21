#include<stdio.h>
#include<string.h>
int main(){
    int i,j,k,m,n;
    scanf("%d %d",&m,&n);

    int alpha1[m][27];
    for(i=0;i<m;i++)
        for(j=0;j<26;j++)
             alpha1[i][j]=0;

    char str[m],ar[m][51];
    for(i=0;i<m;i++) {
        scanf("%s",ar[i]);
        int len = strlen(ar[i]);
        for(j=0;j<len;j++) alpha1[i][ar[i][j]-'a']+=1;
    }
    for(i=0;i<n;i++){
        scanf("%s",str);
        int len = strlen(str);
        int alpha2[27]={0};

        for(j=0;j<len;j++) alpha2[str[j]-'a']+=1;

        for(j=0;j<m;j++){
            int ch=1;
            for(k=0;k<26;k++){
                if(alpha1[j][k] != alpha2[k]){
                    ch=0;
                    break;
                }
            }
            if(ch) printf("%s ",ar[j]);
        }
        printf("\n");
    }
}
/*
8 3
final
fnali
fnial
fianl
title
ttile
tilte
equal
fanil
reply
title
*/
