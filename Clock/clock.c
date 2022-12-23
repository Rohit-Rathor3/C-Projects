#include<stdio.h>
#include<conio.h>
//#include<time.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{  
int second=0,minute=0,hour=0;

while(1)
{ system("cls");
printf("\n\n\t\t-----------------------------------------------------------------------------------------");
printf("\n                                ------------------- CLOCK --------------------------");
printf("\n\t\t-----------------------------------------------------------------------------------------\n\t\t\t\t\t\a");
printf("%02d :%02d :%02d\n\t",second,minute,hour);
fflush(stdout);
second++;
if(second==60)
{
	minute++;
	second=0;

if(minute==60)
{
	hour+=1;
	minute=0;

if(hour==24)
{
	hour=0;
	minute=0;
	second=0;
}
}

}
sleep(1);
}
return 0;
	
}
