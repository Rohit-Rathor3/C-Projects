// This is a fibonacci series program
//Fibonacci series - > It is a sequence where , the next term is the sum of the previous two terms.
// The first two terms of this series are 0 and 1.
#include<stdio.h>
int main(void){
    int i, n , t1=0 ,t2=1;
    int next_t = t1+t2;
    printf("\n-------------------------------------------------------------------------------------------------------------------------------");
    printf("\n                ------------------------------- FIBONACCI SERIES ------------------------------------------");
    printf("\n-------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t Enter the number of terms :- ");
    fflush(stdin);
    scanf("%d",&n);
    printf("\n\t Fibonacci Series :- %d, %d,",t1,t2);
    for(i=3;i<= n ; i++)
    {
        printf(" %d,",next_t);
        t1=t2;
        t2=next_t;
        next_t=t1+t2;
    }
    return 0;
}