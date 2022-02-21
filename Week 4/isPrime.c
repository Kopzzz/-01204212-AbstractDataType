#include <stdio.h>
#include<math.h>
int main(){
    int n,i,ch=1;
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++){
        if (n%i==0)  ch=0;
    }
    if(ch==1 && n>=2) printf("1");
    else printf("0");
}
//O(n^(1/2))

