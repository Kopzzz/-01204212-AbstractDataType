#include<stdio.h>
#include<math.h>
int side[28];
int main(){
    int r,c,i,ans=0,tmp,row,col,area;
    scanf("%d %d",&r,&c);
    tmp = r*c;
    for(i=0;i<=20;i++) side[i] = pow(2,i);
    for(i=1;i<17;i++){
        row=r/side[i];
        col=c/side[i];
        area=pow(side[i],2);
        ans+=(tmp - (row)*(col)*area) / (side[i-1]*side[i-1]);
      //  printf("%d %d %d %d %d %d\n",ans,tmp,row,col,area,side[i-1]*side[i-1]);
        tmp = row*col*area;
    }
    printf("%d",ans);
}
//O(log2(100000))
