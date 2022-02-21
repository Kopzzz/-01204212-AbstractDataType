#include<stdio.h>
int main(){
    int y,m,d=1,day,i;
    char *months[] =
        {" ",
         "January",
         "February",
         "March",
         "April",
         "May",
         "June",
         "July",
         "August",
         "September",
         "October",
         "November",
         "December"};
    int cm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("Enter year: ");
    scanf("%d",&y);
    printf("Enter month: ");
    scanf("%d",&m);
    printf("====================\n");
    printf("%s %d\n",months[m],y);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for(i=1990;i<y;i++) {
        if((i%4==0 && i%100!=0) || i%400==0) d+=366;
        else d+=365;
    }
    if((y%4==0 && y%100!=0) || y%400==0) cm[1] = 29;
    for(i=0;i<m-1;i++) d+=cm[i];
    int start = d%7;

    for(i=0;i<start;i++) printf("    ");
    for(day=1;day<=cm[m-1];day++){
        if(start%7 == 0 || day == 1)  printf("%3d",day);
        else printf("%4d",day);
        start++;
        if (start%7 == 0) printf("\n");
    }

}
