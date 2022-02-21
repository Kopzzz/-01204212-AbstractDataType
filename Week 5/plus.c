#include<stdio.h>
#include<string.h>
#define SIZE 1000000
char x[1000005],y[1000005],tmpS[1000005];
int main(){
    scanf("%s %s",&x,&y);
    int i,j,tmp=0,plus;
    if(strlen(x)<=strlen(y)){
        strcpy(tmpS,x);
        strcpy(x,y);
        strcpy(y,tmpS);
    }
    int len=strlen(x);
    j=strlen(y)-1;
    for(i=strlen(x)-1;i>=0;i--){
        if(j<0) plus=48;
        else plus=y[j];
        if(x[i]+plus-96+tmp >= 10){
            x[i]= x[i]+plus-96+tmp-10;
            tmp=1;
            if(i==0) x[i]+=10;
        }
        else{
            x[i]= x[i]+plus-96+tmp;
            tmp=0;
        }
        j--;
    }
    for(i=0;i<len;i++) printf("%d",x[i]);
}
/*
94354657669743043298785692374893278427348962874678326498779483279234692369487837489267536
65084675429473847289473894578934758937458973489539887349857984375983745897348957983478947
*/
