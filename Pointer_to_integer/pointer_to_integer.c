#include<stdio.h>
int main()
{  int *a ,b;
int **c;     // This is pointer to pointer variable. It will store the address of pointer. It's Funny....
a=&b;
c=&a;
printf("\n\t-----------------------------------------------------------------------------------------------------------------------");
printf("\n                        ----------------------------- POINTER TO INT --------------------------------------");
printf("\n\t-----------------------------------------------------------------------------------------------------------------------\n\n");
printf("\tEnter a integer number B :- ");
   scanf("\n%d",&b);
   // Every variable has its value and memory location (memory address.)
   // pointer points to same data type variable ex.:- int to int , char to char etc. (data type of variable = data type of pointer).

   printf("The value of B                                              = %d",b);
   printf("\nThis as also value of B (by using derefrence operator '*a') = %d",*a); // derefrence of value at pointer a. (This will print value o b).
   printf("\nThis is address of B (by using &b)                          = %u",&b); // This will print address of b;
   printf("\nThis is also of address of B (By using pointer 'a')         = %u",a);  // This will also print the address of b.
   printf("\nThe value of 'a' (by using pointer derefrence '*c'          = %d",*c); // it will print the value of a but there is nothing except its address. So it will print address of a.
   printf("\nThis is address of 'a' (by using ptr to ptr 'c')            = %u",c);  // It will pr int address of a.
   printf("\nThis is also of address of 'a' (By using '&a')              = %u",&a); // It will also print address of a.
   printf("\nThis is address of 'c' (by using &c)                        = %u",&c);   // It will print address of c.
   int i=0;
   printf("\n------------- This is how , to access memory address of further locations which is not reserved for no variable -------------------\n");
   for(i=0;i<=10;i++)
   {
      printf("\nThe A%d is at %u",i,a);
      printf("\t\tThe value at A%d = %d",i,*c);
      printf("\n");
      a++;
   }

   
   return 1;
}