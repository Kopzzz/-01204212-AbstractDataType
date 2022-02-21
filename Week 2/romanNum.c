#include<stdio.h>
int main(){
    int n,num,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        for(i=0;i<num/1000;i++) printf("M");
        num = num%1000;
        if (num>=900) {
            printf("CM");
            num = num%900;
        }
        if (num>=500){
            printf("D");
            num = num%500;
        }
        if (num>=400) {
            printf("CD");
            num = num%400;
        }
        if (num>=100){
            for(i=0;i<num/100;i++) printf("C");
            num = num%100;
        }
        if (num>=90) {
            printf("XC");
            num = num%90;
        }
        if (num>=50){
            printf("L");
            num = num%50;
        }
        if (num>=40) {
            printf("XL");
            num = num%40;
        }
        if (num>=10){
            for(i=0;i<num/10;i++) printf("X");
            num = num%10;
        }
        if (num>=9) {
            printf("IX");
            num = num%9;
        }
        if (num>=5) {
            printf("V");
            num = num%5;
        }
        if (num>=4) {
            printf("IV");
            num = num%4;
        }
        if (num>=1){
            for(i=0;i<num/1;i++) printf("I");
        }
        printf("\n");
    }
}
