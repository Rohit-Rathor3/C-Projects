#include<stdio.h>
#include<conio.h>
void ASCII();
void findAscci();
int main(void)
{
	int choice;
	start:
		system("cls");
	printf("\n\t1.Find ASCII Value : \n\t2.See ASCCI Chart  \n\t0.Exit\n\t\tEnter Your Choice : ");
	fflush(stdin);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			findAscci();
			break;
		case 2:
		     ASCII();
			 break;
		case 0:
		    exit(0);
		default:
		    printf("\n\tEnter correct choice !!!!!!!!!!!!!!!!\n");
			goto start;		 	
	}
    
    return 0;
}
void ASCII()
{
	int i=0;
    char ch;
    printf("\n\t-----------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t                   ------------------------------------- ASCCI CHART ---------------------------------------------");
    printf("\n\t-----------------------------------------------------------------------------------------------------------------------------------------\n\n");
    for(i;i<=255;i++)
    {
    	printf("\tThe value %d = %c",i,i);
    	if(i%5==0)
    	{
    		printf("\n\n");
		}
        
    }
}
void findAscci()
{
	char character;
    printf("\n\t--------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t                   ------------------------- FIND ASCII VALUE OF A CHARACTER -----------------------------");
    printf("\n\t--------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\tEnter a character : ");
    fflush(stdin);
    scanf("%c",&character);
    printf("\n\t**************************");
    printf("\n\tThe ASSCI value of '%c' = %d",character,character);
    printf("\n\t**************************");
}
