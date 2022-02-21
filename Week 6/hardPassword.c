#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char s[1000005],A[100000],B[100000];
    int i=0,j=0;
    scanf("%s",&s);
    while(s[i]!='x'){
        A[i] = s[i];
        i++;
    }
    i++;
    while(s[i]!='y'){
        B[j] = s[i];
        i++;
        j++;
    }
  //  printf("%s %s %d %d\n",A,B,strlen(A),strlen(B));
    if(strlen(A)==strlen(B)){
        j=strlen(B)-1;
        int ch=1;
        for(i=0;i<strlen(A);i++){
            if(A[i]!=B[j]) ch=0;
            //printf("%c %c\n",A[i],B[j]);
            j--;
        }
        printf("%d",ch);
    }
    else printf("0");
   // printf("%s %s %s",s,A,B);
}
/*
>>> test case #1
1q2w3e4rxr4e3w2q1y
>>> test case #2
1q2w3e4rx1q2w3e4ry
>>> test case #3
1q2w3e4rx1q2w3ey
*/
