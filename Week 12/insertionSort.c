#include<stdio.h>
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++) scanf("%d",&ar[i]);

    for(i=1;i<n;i++){
        for(j=i;j>0;j--){
            if(ar[j]<ar[j-1])
                swap(&ar[j],&ar[j-1]);
        }
        for(j=0;j<n;j++)printf("%d ",ar[j]);
        printf("\n");
    }
}
