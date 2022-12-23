#include<stdio.h>
//#include<conio.h>
#include<string.h>
int main()
{
	char a[200],name[15];
	
	int i,count=1;
    printf("\n--------------------------------------------------------------------------------------------------------------------------------");
    printf("\n             ---------------------------------------- WORD COUNTER --------------------------------------------");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\tEnter Your Name : ");
    gets(name);
	printf("\n\t\t Enter Your Text Below  :\n\n\t\t");
	gets(a);
	
    i=0;

    for (i=1 ; i<strlen(a) ;i++)
    {
    	if(a[i]==' ')
    	count++;
    	
	}
	printf("\n\n\t******** Hlo , %s\n\t\t you typed %d words ",name,count);
	getch();
	return 0;
}
