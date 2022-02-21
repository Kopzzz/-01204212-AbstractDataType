#include <stdio.h>
#include <math.h>
 int main(){
    double i,N,g0,g,pre;
    scanf("%lf %lf",&N,&g0);
    while(1){
        g = 0.5*(g0 + N/g0);
        printf("%.10f %.10f %.10f\n",g,g0,fabs(g-g0));
        if(fabs(g-g0) < 1e-10){
            printf("%.10f",g);
            break;
        }
        g0=g;
    }
 }
