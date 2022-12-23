#include<stdio.h>
#include<ctype.h>
void halfPyramid();
void halfPyramidNumber();
void halfPyramidAlphabet();
void invertedHalfPyramid();
void invertedHalfPyramidNumber();
void fullPyramid();
void fullPyramidNUMBER();
void invertedFullPyramid();
void pascalTriangle();
void floydTriangle();

void menu(){
    int choice;
    start:
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                      -------------------------- PRINT PATTERNS ------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    
    printf("\n\n\t 1. Half Pyramid '*' \n\t 2. Half Pyramid 'number' \n\t 3. Half Pyramid 'alphabet' \n\t 4. Inverted Half Pyramid '*' \n\t ");
    printf("5 Inverted Half Pyramid 'number' \n\t 6. Full Pyramid '*' \n\t 7. Full Pyramid 'number' \n\t 8. Inverted Full Pyramid '*' \n\t");
    printf("9. Pascals's Triangle \n\t 10. Floyd's Triangle \n\t 0. Exit \n\n\t\t Enter your choice :- ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        halfPyramid();
        break;
        case 2:
        halfPyramidNumber();
        break;
        case 3:
        halfPyramidAlphabet();
        break;
        case 4:
        invertedHalfPyramid();
        break;
        case 5:
        invertedHalfPyramidNumber();
        break;
        case 6:
        fullPyramid();
        break;
        case 7:
        fullPyramidNUMBER();
        break;
        case 8:
        invertedFullPyramid();
        break;
        case 9:
        pascalTriangle();
        break;
        case 10:
        floydTriangle();
        break;
        case 0:
        exit(0);
        break;
        default :
        printf("\n\n\t Please enter correct choice !!!!!!!!!");
        goto start;


    }
}

int main(){

    menu();
    return 0;
}
void halfPyramid(){
    int i ,j ,rows;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                   ----------------------------- HALF PYRAMID OF '*' --------------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Enter number of rows :- ");
    fflush(stdin);
    scanf("%d",&rows);
    for(i=1 ; i<=rows ; i++)
    {
        for(j=1; j<=i ; j++)
        {
            printf(" *");
        }
        printf("\n");
    }
}

void halfPyramidNumber(){
    int i ,j ,rows;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                   ----------------------------- HALF PYRAMID OF NUMBERS --------------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Enter number of rows :- ");
    fflush(stdin);
    scanf("%d",&rows);
    for(i=1 ; i<=rows ; i++)
    {
        for(j=1; j<=i ; j++)
        {
            printf(" %d",j);
        }
        printf("\n");
    }
}

void halfPyramidAlphabet(){
    int i ,j;
    char rows , character='A' , smallcharacter = 'a';
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                   ----------------------------- HALF PYRAMID OF ALPHABET --------------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Enter last alphabet , you want to print in the last row  :- ");
    fflush(stdin);
    scanf("%c",&rows);
    if(rows==toupper(rows))
    {
        for(i=1 ; i<=(rows - 'A' +1 ) ; i++)
    {
        for(j=1; j<=i ; j++)
        {
            printf(" %c",character);
        }
        character++;
        printf("\n");
    }
    }
    else
    {
        for(i=1 ; i<=(rows - 'a' +1 ) ; i++)
    {
        for(j=1; j<=i ; j++)
        {
            printf(" %c",smallcharacter);
        }
        smallcharacter++;
        printf("\n");
    }
    }
    
}


void invertedHalfPyramid(){
    int i ,j ,rows;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                   ------------------------- INVERTED HALF PYRAMID OF '*' ----------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Enter number of rows :- ");
    fflush(stdin);
    scanf("%d",&rows);
    for(i=rows ; i>=1 ; i--)
    {
        for(j=1; j<=i ; j++)
        {
            printf(" *");
        }
        printf("\n");
    }
}

void invertedHalfPyramidNumber(){
    int i ,j ,rows;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                   -------------------------- INVERTED HALF PYRAMID OF NUMBERS ------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Enter number of rows :- ");
    fflush(stdin);
    scanf("%d",&rows);
    for(i=rows ; i>=1 ; i--)
    {
        for(j=1; j<=i ; j++)
        {
            printf(" %d",j);
        }
        printf("\n");
    }
}

void fullPyramid(){
    int i ,j=0 ,rows , space;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                      -------------------------- FULL PYRAMID OF '*' ------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Enter number of rows :- ");
    fflush(stdin);
    scanf("%d",&rows);
    for(i=1; i<=rows;i++ , j=0)
    {
        for(space=1; space<=rows -i;space++)
        {
            printf("  ");
        }
        while(j!=2*i-1){
            printf("* ");
            j++;
        }
        printf("\n");
    }

}

void fullPyramidNUMBER(){
    int i ,j=0 ,rows , space ,count=0 , count1=0;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                      -------------------------- FULL PYRAMID OF NUMBERS ------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Enter number of rows :- ");
    fflush(stdin);
    scanf("%d",&rows);
    for(i=1; i<=rows;i++)
    {
        for(space=1; space<=rows -i;space++)
        {
            printf("  ");
            count++;
        }
        while(j!=2*i-1){
            if(count<=rows -1)
            {
                 
            printf("%d ",i+j);
            count++;
            }
            else
            {
               ++count1;
            printf("%d ",(i+j-2*count1));
            }
            j++;
                    }
                    count1 = count = j =0;
        printf("\n");
    }

}

void invertedFullPyramid(){
    int i ,j,rows , space;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                      -------------------------- FULL INVERTED PYRAMID OF '*' ------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t Enter number of rows :- ");
    fflush(stdin);
    scanf("%d",&rows);
    for(i=rows; i>=1;i--)
    {
        for(space=0; space<rows -i;space++)
            printf("  ");
        for(j=i;j<=2*i-1;j++)
            printf("* ");
        for(j=0;j<i-1;j++)
           printf("* ");
          printf("\n");
    }

}


void pascalTriangle(){

    int rows , coef=1 , space , i,j;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                      -------------------------- PASCAL'S TRIANGLE ------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t Enter the number of rows  :- ");
    fflush(stdin);
    scanf("%d",&rows);
    for(i=0 ; i<rows ; i++){
        for(space=1; space<=rows-i;space++)
        printf("  ");
        for(j=0; j<=i ; j++){
            if(j==0 || i==0)
            coef = 1;
            else
            coef = coef*(i-j+1)/j;
            printf("%4d",coef);
        }
        printf("\n");
    }
    }

    void floydTriangle()
    {
        int rows ,i,j,number=1;
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
    printf("                      -------------------------- FLOYD'S TRIANGLE ------------------------------");
    printf("\n -------------------------------------------------------------------------------------------------------------------------------");
        printf("\n\n\tEnter the number of rows :- ");
        scanf("%d",&rows);
        for(i=1 ; i<=rows ; i++){
            for(j=1; j<=i ; j++){
                printf(" %d",number);
                number++;
            }
            printf("\n");
        }
    }