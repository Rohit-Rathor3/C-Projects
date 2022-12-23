#include<stdio.h>
#include<unistd.h>
#include<windows.h>
#include<conio.h>

struct student
{
	int id;
	char name[20];
	int classs;
	char contact[10];
	char address[30];
}s;
FILE *fp;
void addstudent(void);
void SeeRecord(void);
void Search(void);
int main()
{    int choice;
     system("cls");
     //system("color f3");
     label:
     printf("\n\t1. Add New Student\n\t2. See All Record\n\t3. Search Student\n\t");
     printf("\tEnter Your Choice : ");
     scanf("%d",&choice);
     switch(choice)
     {
     	case 1:
     		addstudent();
     		system("cls");
     		break;
     	case 2:
		    SeeRecord();
		    system("cls");
			break;
		case 3:
		    Search();
		    system("cls");
			break;	
		default:
		    printf("Kindly Enter Right Choice !!!!!!!!!!!!\n");
		    sleep(2);
		    system("cls");
			break;		
	 }
	 goto label;
	return 0;
}
void addstudent(void)
{   
    system("cls");
    system("color f3");
    printf("------------------------------------------------------Student's Registraton---------------------------------------------\n");
	printf("\n\tEnter Student's id    : ");
	scanf("%d",&s.id);
	printf("\n\tEnter student's' Name : ");
	gets(s.name);
	gets(s.name);
	printf("\n\tEnter Class Name      : ");
	scanf("%d",&s.classs);
	printf("\n\tEnter Contact Number  : ");
	gets(s.contact);
	gets(s.contact);
	printf("\n\tEnter Full Address    : ");
	gets(s.address);
	fp=fopen("add_search_from_file.bin","ab+");
	if(fp==NULL)
	{
		printf("Unable to create file !");
	}
    else
    {
	fwrite(&s,sizeof(s),1,fp);
    }
	fclose(fp);
	
	printf("\n\n\t\t\t\t\t\aStudent's Detaile saved successfully !!!!!");
	getch();
}
void SeeRecord(void)
{   
    int got=0,i=0;
	fp=fopen("add_search_from_file.bin","rb");
	if(fp==NULL)
	{
		printf("Unable to open the file !\n");
	}
    else
    {
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		got=1;
		i++;
		printf("\n-----------------------------------------------------\n");
		printf("\tStudent --> %i ",i);
		printf("\n\tId      : %d",s.id);
		printf("\n\tName    : %s",s.name);
		printf("\n\tClass   : %d",s.classs);
		printf("\n\tCont. No. : %s",s.contact);
		printf("\n\tAddress  : %s",s.address);
	}
	if(got==0)
	{
		printf("\nThere is no record !!!!!!!!!!");
	}
    }
	fclose(fp);
	getch();
}
void Search(void)
{
	int ide,i=0;
	printf("\n\tEnter Student Id : ");
    scanf("%d",&ide);
	fp=fopen("add_search_from_file.bin","rb");
	if(fp==NULL)
	{
		printf("Unable to open the file !\n");
	}
    else
    {
    	rewind(fp);
	while(fread(&s,sizeof(s),1,fp)==1)
	{   
	    
		if(s.id==ide)
		{
		i=1;
		printf("\n-----------------------------------------------------\n");
		printf("\n\tId      : %d",s.id);
		printf("\n\tName    : %s",s.name);
		printf("\n\tClass   : %d",s.classs);
		printf("\n\tCont. No. : %s",s.contact);
		printf("\n\tAddress  : %s",s.address);
	   }
	}
	}
	fclose(fp);
	
	if(i==0)
	{
		printf("\nThere is  no stuents with this Id !!!!!!!!!!");
	}
	getch();
}
