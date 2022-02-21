#include <stdio.h>
long fact[1000005]={1,1},check[1000005];

int main(){
    int i,n,num;
    for(i=1;i<=1000000;i++){
        fact[i] = fact[i-1]*i;
    }
    for(i=1;i<=1000000;i++){
        n=i;
        while(n){
            check[i]+=fact[n%10];
            n =n/10;
        }
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        for(i=num-1;;i--){
            if (i==check[i]){
                printf("%d\n",i);
                break;
            }
        }
    }
}
