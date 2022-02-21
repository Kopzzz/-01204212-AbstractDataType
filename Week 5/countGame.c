#include<stdio.h>
int ar[1000005],k;
int check(int count){
    int j,tmp;
    for(j=0;j<8;j++){
        tmp=count%10;
        count/=10;
        if(tmp==k) return 1;
    }
    return 0;
}
int main(){
    int n,i,count=1,tmp;
    scanf("%d %d",&n,&k);
    tmp=n;
    for(i=1;i<=n;i++){
        scanf("%d",&ar[i]);
    }
    i=1;
    while(1){
        if(i>n) i=1;
        while(ar[i]<0) {
            i++;
            if(i>n) i=1;
        }
        if((count%k==0 || check(count))&& ar[i]>=0){
            ar[i]--;
            if(ar[i]<0) tmp--;
          //  printf("%d %d %d %d\n",i,ar[i],tmp,count);
        }
        i++;
        count++;
       // printf("%d\n",tmp);
        if (tmp==1) break;
    }
    for(i=1;i<=n;i++){
        if(ar[i]>=0) {
            printf("%d",i);
            break;
        }
    }
}
/*
10 9
97 65 84 21 5 43 58 18 63 91 99
1

5 2
1 5 3 1 2
2

5 3
1 5 3 1 2
2
*/
