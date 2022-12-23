#include<stdio.h>
#include<unistd.h>
#include<conio.h>
#include<string.h>
struct student
{
	int id;
	char name[20];
	int classs;
	char contact[10];
	char address[30];
}s;
int iden;

FILE *fp;
void addstudent(void); // To add a new student
void SeeRecord(void);  // To see all records 
void Search(void);     // To search a particular student by his/her Id
void update(void);     // To update record of student
void getname();        // To get name of student  duringregistration
//int getid(void);      // To get id of student
void del(void);      // To Delete a particular record by Id
void welcome(void);
int main()
{    int choice;
     system("cls");
     //system("color f3");
     label:
     welcome();	
     printf("\n\t1. Add New Student\n\t2. See All Record\n\t3. Search Student\n\t4. Update Record\n\t5. Delete Record\n\t");
     printf("\n\t Kindly Enter Your Choice : ");
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
		case 4:
		    update();
		    system("cls");
			break;	
		case 5:
		    del();
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
                      /////////////////// Welcome fuction
                       
void welcome()
{
    printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("                                     STUDENT'S MANAGEMENT SOFTWARE\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("***************************************** Welcome To Drona Classes ******************************************\n");
}
                               
                                 //////////// Function to Add a new student
                                 
void addstudent(void)
{   
    int a,x=0;
	int i=0;

    system("cls");
    //system("color f3");
    add:
    welcome();
    printf("\n\t----------------------------------------RAGISTER A NEW STUDENT ---------------------------------");
   label:
	printf("\n\tEnter Student Id : ");
	fflush(stdin);
    scanf("%d",&s.id);
	 if(s.id<0 || s.id>100)
	 {
	 	printf("\n\tPlz enter ID between 1 and 100\n");
	 	goto label;
	 }
    getname();

	fflush(stdin);
	printf("\n\tEnter Class Name      : ");
	fflush(stdin);
	scanf("%d",&s.classs);
	fflush(stdin);
	printf("\n\tEnter Contact Number  : ");
	fflush(stdin);
	gets(s.contact);
	fflush(stdin);
	printf("\n\tEnter Full Address    : ");
	fflush(stdin);
	gets(s.address);
	fp=fopen("StudentManagement.bin","ab+");
	if(fp==NULL)
	{
		printf("Unable to create file !");
	}
    else
    {
	fwrite(&s,sizeof(s),1,fp);
    }
	fclose(fp);
	
	printf("\n\n\t\t\t\t\t\aStudent's Details Saved Successfully !!!!!");
	getch();
}                     

                         ////////////// Function to see all ragisterd Students

void SeeRecord(void)
{   
    system("cls");
    int got=0,i=0;
    welcome();
    printf("------------------------------------------------------------------------------------------\n");
    printf("                                 ALL RAGISTRATED STUDENTS                                    \n");
    printf("------------------------------------------------------------------------------------------\n");
	fp=fopen("StudentManagement.bin","rb");
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
		fflush(stdout);
		printf("\n\tId      : %d",s.id);
		fflush(stdout);
		printf("\n\tName    : %s",s.name);
		fflush(stdout);
		printf("\n\tClass   : %d",s.classs);
		fflush(stdout);
		printf("\n\tCont. No. : %s",s.contact);
		fflush(stdout);
		fflush(stdout);
		printf("\n\tAddress  : %s",s.address);
	}
	fclose(fp);
	if(got==0)
	{
		printf("\nThere is no record !!!!!!!!!!\n\n");
	}
    }
    printf("\n\n\t\t----------------------\n");
    printf("\t\tTotal Students ---> %d\n",i);
    printf("\t\t----------------------\a\n");
    
	
	getch();
}                   


                                //////////// Function to Search a record
                                
void Search(void)
{
	int ide,i=0;
	system("cls");
	welcome();
    printf("------------------------------------------------------------------------------------------\n");
    printf("                                 SEARCH A STUDENT'S RECORD                                 \n");
    printf("------------------------------------------------------------------------------------------\n");
	printf("\n\tEnter Student Id : ");
    scanf("%d",&ide);
	fp=fopen("StudentManagement.bin","rb");
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
		printf("\n\tId        : %d",s.id);
		printf("\n\tName      : %s",s.name);
		printf("\n\tClass     : %d",s.classs);
		printf("\n\tCont. No. : %s",s.contact);
		fflush(stdout);
		printf("\n\tAddress   : %s",s.address);
		printf("\n-----------------------------------------------------\n\a");
	   }
	}
	}
	fclose(fp);
	
	if(i==0)
	{
		printf("\n\t\t\aThere is  no stuents with this Id !!!!!!!!!!");
	}
	getch();
}  

                               ////////// Function To Update Student's Record
                               
void update(void)
{
	int j=0,id;
	system("cls");
	welcome();
    printf("------------------------------------------------------------------------------------------\n");
    printf("                                 UPDATE A STUDENT'S RECORD                                  \n");
    printf("------------------------------------------------------------------------------------------\n");
	again:
	printf("\n\tEnter Student Id : ");
    scanf("%d",&id);
	fp=fopen("StudentManagement.bin","rb+");
	if(fp==NULL)
	{
		printf("Unable to open the file !\n");
	}
	rewind(fp);
	while(fread(&s,sizeof(s),1,fp)==1)
	{   
		if(s.id==id)
		{
		j=1;
		break;
	}
	//	fseek(fp,0,SEEK_CUR);
	
		
	}
	
	if(j==0)
	{
		printf("\n\tYou entered wrong id !!!!!!!!!!!!");
		goto again;
		rewind(fp);
	}   
	    
		printf("\n\t\t-------------------- Existing Details of student -------------------");
		printf("\n-----------------------------------------------------\n");
		printf("\n\tId        : %d",s.id);
		printf("\n\tName      : %s",s.name);
		printf("\n\tClass     : %d",s.classs);
		printf("\n\tCont. No. : %s",s.contact);
		printf("\n\tAddress   : %s",s.address);
		printf("\n-----------------------------------------------------\n\a");
		
	    fseek(fp,-(sizeof(s)),SEEK_CUR);
		printf("\n\t\t-------------------- Enter new Details of student -------------------");
		printf("\n\tEnter id              : ");
		fflush(stdin);
		scanf("%d",&s.id);
	    getname();
		printf("\n\tEnter Class           : ");
		fflush(stdin);
		scanf("%d",&s.classs);
		printf("\n\tEnter Contact         : ");
	    fflush(stdin);
	    gets(s.contact);
	    fflush(stdin);
		printf("\n\tEnter Address         :");
		fflush(stdin);
		gets(s.address);
		//fflush(stdin);
		fwrite(&s,sizeof(s),1,fp);
		printf("\n\t\t\t\a  ********* Record Updated Successfully !!!!!! *********");
		getch();
	

	fclose(fp);
}
                                    ////////////// Function to Delete a record by entring Id 
void del(void)
{
	FILE *fp1;
	FILE *fp2;
	int l;
	int ide;
	fp1=fopen("StudentManagement.bin","rb");
	fp2=fopen("StudentManagementDelete.bin","wb");
	if(fp1==NULL||fp2==NULL)
	{
		printf("\n\t Error : Unable to open the file !!!!!!");
		sleep(2);
		return;
    }
    welcome();
    printf("\n\t------------------------------------------ Delete Student's Record ---------------------------------");
    printf("\n\tEnter Id     : ");
    fflush(stdin);
    scanf("%d",&ide);
    while(fread(&s,sizeof(s),1,fp1)==1)
    {
          if(ide==s.id)
          {
          	l=1;
          }
          else
          {
			fwrite(&s,sizeof(s),1,fp2);
		  }
    	
	}
	fclose(fp1);
	fclose(fp2);
	if(l!=1)
	{
		printf("\n\t There is no record with this Id!!!!!!!!!!!!\n");
		return;
	}
	else
  {
	fp1=fopen("StudentManagement.bin","wb");
	fp2=fopen("StudentManagementDelete.bin","rb");
	if(fp1==NULL || fp2==NULL)
	{
		printf("\n\t Error : open file !!!!\n");
		return;
	}
	else
	{
		// Coping Data from Delete file to Sourse file
	   while(fread(&s,sizeof(s),1,fp2)==1)
	   {
		fwrite(&s,sizeof(s),1,fp1);
	    }
	}
	fclose(fp1);
	fclose(fp2);
  }
	fp2=fopen("StudentManagementDelete.bin","wb");
	fclose(fp2);
	printf("\n\tRecord has been deleted successfully!!!!!!!!!!!!\n");
	getch();
	}
	 
	
void getname()
{
	int a=0,x=0;
	register int i=0;
	label:	
	printf("\n\tEnter Name            : ");
	fflush(stdin);
	gets(s.name);
	a=strlen(s.name);
	for(;i<a;i++)
	{
	if((s.name[i]>='a' && s.name[i]<='z')||(s.name[i]>='A' && s.name[i]<='Z')|| (s.name[i]==32))
	{
		x=1;
	}
	else
	{  
	    printf("\n\t\t\a **************Plz enter correct name!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	   
		goto label;
	}
		
	}
	return;
}
                                                    
