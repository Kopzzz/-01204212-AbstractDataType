#include<stdio.h>
#include<math.h>
int main(){
    int I[]={-1,0,1,0},J[]={0,1,0,-1},n,x=0,y=0,pos=100000;
    char w;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&w);
        if (w=='L') pos--;
        if (w=='R') pos++;
        if (w=='F') {
            x+=I[pos%4];
            y+=J[pos%4];
            //printf("%d %d \n",x,y);
        }
    }
    printf("%.4f",sqrt((x*x)+(y*y)));

}
//FFRFFRFLFRFFRFLFRF
//FLFF
