#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void creatAndWrite();
void openFILE();
void op1TotalWords();
void op2TotalCharacter();
void op3SearchWord();
void op4CopyFile();
void menu();
int main()
{   menu();
    getch();
    return 0;
}
void menu()
{
    int choose1,choose2;
    again:
   // system("cls");
    printf("\n\t\a----------------------------------------------------------------------------------------------------------------------------");
    printf("\n                 ------------------------------------- FILE HANDLING IN C SOME OPERATIONS ----------------------------------");
    printf("\n\t ----------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t1.Creat A New File :\n\t2.Open A File : \n\t3.Operations On File : \n\t0.Exit : \n\tEnter Your Choice : ");
    fflush(stdin);
    scanf("%d",&choose1);
    switch(choose1)
    {
        case 1:
        creatAndWrite();
        break;
        case 2:
        openFILE();
        break;
        case 3:
        printf("\n\t1.Find Total Words In A File : \n\t2.Find Total characters in a File : \n\t3.Search A Character : \n\t4.Copy File : \n\t 0.Exit");
        printf("\n\tEnter Your Choice : ");
        scanf("%d",&choose2);
        switch(choose2)
        {
            case 1:
            op1TotalWords();
            break;
            case 2:
            op2TotalCharacter();
            break;
            case 3:
            op3SearchWord();
            break;
            case 4:
            op4CopyFile();
            break;
            case 0:
            exit(0);
            break;
            default :
            printf(" \n\t\t Error -> Plz Choose Correct Option !! :");
            goto again;

        }
        goto again;
       case 0:
        exit(0);
        break;
        default :
        printf(" \n\t\t Error -> Plz Choose Correct Option !! :");
        goto again;
    }
    goto again;
}
void creatAndWrite(){
    char fname[20], ch[15];
    char choice;
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n             ------------------------------- CREATE A FILE --------------------------------------------");
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\nEnter File Name (only txt file ex.:- file.txt) :- ");
    fflush(stdin);
    gets(fname);
    FILE *fp;
    fp=fopen(fname,"w");
    if(fp==NULL)
    {
        printf("\n\t Error -> Unable to Create the file : ");
    }
    else
    {   
        printf("\n\t File Created Successfully !!!!!!!\n");
        printf("\n\t Do you want to write in file (y/n)\n\t\t\t\t\t");
        scanf("%c",&choice);
        if(choice=='n')
        {
           printf("OK!!!!!!");
        }
        else if(choice=='y')
        { 
        printf("\n\t Enter your file text : - ");
        printf("                                                                                      ---- Write 'SAVE' to save the file ----\n\t\n\t\t" );
        while(1)
        {
        fflush(stdin);    
        gets(ch);
        if(strcmp(ch,"SAVE")==0)
        {   
            printf("\nYour File Saved Successfully !!!!");
            break;
        }
        else
        {
            fputs(ch,fp);
        }
    
       }
       
       
    }
       {
           exit(0);
       }
    
    }
}
void openFILE(){
 FILE *fp;
	char file[50] ,ch;
	printf("\n\t---------------------------------------------------------------------------------------------------------------------");
	printf("\n\t             --------------------------OPEN A FILE AND READ IT --------------------------------------");
	printf("\n\t---------------------------------------------------------------------------------------------------------------------");
	printf("\n\n\tEnter file name : ");
    fflush(stdin);
	gets(file);
	fp=fopen(file,"r");
	if(fp==NULL)
	{
		printf("\n\t\a*************** Error -> File does not exit ***************************");
	}
	else
	{
	printf("\n********************************** FILE READING START  ***********************************\n");	
    while(1)
	{
		ch=fgetc(fp);
		if(ch==EOF)
		   break;
		   printf("%c",ch);
	}
	printf("\n************************************** END OF FILE *****************************************");
	fclose(fp);
	}
    //getch();
}

void op1TotalWords(){
   FILE *fp;
   int i=0;
   char ch ,fname[20];
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n                -------------------------- FIND TOTAL WORDS IN FILE------------------------------------");
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\tEnter file name : ");
    fflush(stdin);
	gets(fname);
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        printf("\n\t Error -> File does not exist : ");
    }
    else
    {
        while(1)
	{
		ch=fgetc(fp);
		if(ch==EOF)
        {
            break;

        }
		else
        {
              if(ch==' ')
              i++;
        }
	}
    if(i!=0)
    {
        i+=1;
    }
    printf("\nTotal words in file are = %d",i);
    printf("\n*******************************");
        
    }
    fclose(fp);
}
void op2TotalCharacter(){
   FILE *fp;
   int i=0,j=0;
   char ch ,fname[20];
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n               -------------------------- FIND TOTAL CHARACTERS IN A FILE ---------------------");
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\tEnter file name : ");
    fflush(stdin);
	gets(fname);
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        printf("\n\t Error -> File does not exist : ");
    }
    else
    {
        while(1)
	{
		ch=fgetc(fp);
		if(ch==EOF)
        {
            break;

        }
		else
        {    
            if(ch==' ')
            { 
                j++;
            }
            else
            {
                i++;
            }
        }
              
    }   printf("\n*********************************");
        printf("\n\tTotal characters in file = %d",i);
        printf("\n\tTotal Spaces in file     = %d",j);
        printf("\n*********************************");
	}
    fclose(fp);    
    }

void op3SearchWord()
    {
    FILE *fp;
    int i=0;
    char ch ,word,fname[20];
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n                 ---------------------------- SEARCH A CHARACTER ------------------------------");
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\tEnter file name : ");
    fflush(stdin);
	gets(fname);
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        printf("\n\t Error -> File does not exist : ");
        
    }
    else
    {  
        printf("\n\tEnter the character , you want to search : ");
        fflush(stdin);
        scanf("%c",&word); 
        while(1)
	{
		ch=fgetc(fp);
        if(ch==EOF)
        {
            break;
        }
        if(ch==word)
        {
            i++;
        }  
         
    }
    
      if(i==0)
    {
        printf("\n\tCharacter Not Found : ");
        //exit(0);
    }
    else
    {
        printf("\n\tCharacter Found %d times",i);
    }
    

    }
    
    fclose(fp);
}
void op4CopyFile()
{

    char c;
    FILE *fp1,*fp2;
    char f1name[20],f2name[20];
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n             ------------------------------- COPY A FILE --------------------------------------------");
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n\tEnter File1 name , you want to copy : ");
    fflush(stdin);
    gets(f1name); 
    printf("\n\t Enter file2 name , in which you want to copy file1 : ");
    fflush(stdin);
    gets(f2name);
	fp1=fopen(f1name,"r");
	fp2=fopen(f2name,"w");
	if(fp1==NULL&&fp2==NULL)
	{
		printf("Unable to open the file : error to open the file ");
		//exit(1);
	}
	while(1)
	{
	    c=fgetc(fp1);
		if(c==EOF)
		{
			break;
		}
        else
        {
          fputc(c,fp2);   
        }
	}
    printf("\n\t*******************************************************");
	printf("\n\tFile1  copied to file2 successfullly!!!!!!!!!!!!!!");
    printf("\n\t*******************************************************");
	fclose(fp1); 
	fclose(fp2);
	//getch();
}
