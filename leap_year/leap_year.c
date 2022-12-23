#include<stdio.h>
int main(void){
    int year;
    printf("\n-------------------------------------------------------------------------------------------------------------------------------");
    printf("\n              ---------------------------- CHECK A YEAR LEAP OR NOT ------------------------------------------");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\tEnter a year : ");
    fflush(stdin);
    scanf("%d",&year);
    if(year<=0 )
    {
        printf("\n\tPlease Enter a correct year !!!!!!!!!");

    }
    else if(year%4==0 || year%400==0)
    {
        printf("\n\t %d is a leap year ",year);
    }
    else{
        printf("\n\t%d is not a leap year ",year);
    }
    return 0;
}