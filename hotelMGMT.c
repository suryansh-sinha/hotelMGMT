#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void add();
void list();
void edit();
void delete1();
void search();
void login();

struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];	
	char email[30];
	char period[10];
	char arrivaldate[10];
}s;

int main(){     // MAIN FUNCTION	
	int i=0;	
	char customername;
	char choice;

	system("cls");
	printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                         |\n");
	printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
	printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
	printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("|                                                                         |\n");                       
	printf(" -------------------------------------------------------------------------\n");
 	
	printf("\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*        WELCOME TO HOTEL DESERT CAVE           *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n");
	
	printf(" \n Press any key to continue:");	
	getch();

    system("cls");
    login();
    system("cls");

	while (1)      // INFINITE LOOP
	{
		system("cls");

		 for(i=0;i<80;i++)
			printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
			printf("-");

		printf("\n");
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");	

		choice=getche();	//getche waits for keypress input and prints the character on screen too.
		choice=toupper(choice);

		switch(choice)
		{	
			case '1':
				add();
				break;
			case '2':
				list();
				break;
			case '3':
				delete1();
				break;
			case '4':
				search();
				break;
			case '5':
				edit();
				break;
			case '6':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
				printf("\n\t Press any key to exit...");
				getch();
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();	//Waits for any key press and then restarts the main menu because it's in an infinite loop.
		}
	}
}

void login(){	
	int tries = 0,i = 0;
    char c = ' '; 
    char pword[10], uname[10];
    char user[10]="user";
    char pass[10]="pass";
    do
	{
		system("cls");
	    printf("\n  **************************  LOGIN FORM  **************************  ");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &uname); 
		printf(" \n                       ENTER PASSWORD:-");
		//Inputting password.
		while(i<10)
		{
			pword[i] = getch();
			c = pword[i];
			if(c==13)
				break;	//ASCII 13 is character for carriage return i.e. Enter key. If enter key pressed, break out of loop.
			else
				printf("*");	//Else print * instead of the character entered in console.
			i++;
		}
		pword[i]='\0';	//Each string is ended by \0 so to compare, we must add this to the password too.
		i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
		{
			printf("\n\n\n\t WELCOME! LOGIN SUCCESSFUL");		
			break;
		}
		else
		{
			printf("\n\n\n\t SORRY! LOGIN UNSUCESSFUL!");
			tries++;			
			getch();	//Waits for key press to restart loop again until tries exceeds 4.
		}
	}
	while(tries<=4);

	if (tries>4)
	{
		printf("\nSorry you have entered the wrong username and password for four times!");		
		getch();
		exit(0);
	}
	system("cls");	
}

void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");	//If file already exists, it will open in append mode.
	//If file does not exist, fopen returns null. w+ mode creates an empty file for reading and writing.
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\nProcess completed press any key to continue!! ");
		getch();
	}
	while(1)	//INFINITE LOOP
	{
		system("cls");
		printf("\nEnter Customer Details:");
		printf("\n**************************");
		printf("\nEnter Room number: ");
		scanf("%s",s.roomnumber);
		fflush(stdin);
		printf("\nEnter Name: ");
		gets(s.name);
		fflush(stdin);
		printf("\nEnter Address: ");
		gets(s.address);
		fflush(stdin);
		printf("\nEnter Phone Number: ");
		scanf("%s",s.phonenumber);
		fflush(stdin);
		printf("\nEnter Nationality: ");
		scanf("%s",s.nationality);
		fflush(stdin);
		printf("\nEnter Email: ");
		scanf(" %s",s.email);
		fflush(stdin);
		printf("\nEnter Period(\'x\'days): ");
		scanf("%s",s.period);
		fflush(stdin);
		printf("\nEnter Arrival date(dd/mm/yyyy): ");
		scanf("%s",s.arrivaldate);
		fflush(stdin);
		fwrite(&s,sizeof(s),1,f);
		printf("\n\nRoom is successfully booked!!");
		printf("\nPress Y key to add another customer's detail, any other key to exit: ");
		test=getche();
		if(test!=89 && test!=121)
			break;			
	}
	fclose(f);
}

void list()
{
	FILE *f;
	struct CustomerDetails temp;
	int i;
	if((f=fopen("add.txt","r"))==NULL){
		printf("Record file does not exist. Press any key to go back to main menu...");
		getch();
		exit(0);
	}

	system("cls");
	printf("ROOM     ");
	printf("NAME\t\t      ");
	printf("ADDRESS\t\t\t");
	printf("PHONE NUMBER    ");
	printf("NATIONALITY     ");
	printf("EMAIL \t\t\t\t");
	printf("PERIOD   ");
	printf("ARRIVAL   \n");
	
	for(i=0;i<139;i++)
		printf("-");

	while(fread(&temp,sizeof(struct CustomerDetails),1,f))
	{
		printf("\n%-8s %-20s %-25s %-15s %-15s %-30s %-8s %-10s\n", temp.roomnumber, temp.name, temp.address, temp.phonenumber, temp.nationality, temp.email, temp.period, temp.arrivaldate);
	}

	for(i=0;i<139;i++)
		printf("-");

	fclose(f);
	printf("\nPress any key to continue...");
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the room number to be deleted from the database: ");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       
		printf("\n\nRecords of customer in this room number not found!!");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\n The Customer is successfully removed...");
	printf("\n Press any key to go to main menu...");
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: ");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f))
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			break;
		}
	}
	if(flag==1){	
		printf("\n\tRequested Customer could not be found!");
	}
	printf("\n Press any key to go to main menu...");
	getch();
	fclose(f);
}

void edit()
{
	FILE *f, *temp;
	temp = fopen("temp.txt", "w");
	int k=1;
	char roomnumber[20];
	long int size = sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit: ");
	scanf("%s",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f))
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			k=0;
			printf("\nEnter Room number: ");
			scanf("%s",s.roomnumber);
			fflush(stdin);
			printf("\nEnter Name: ");
			gets(s.name);
			fflush(stdin);
			printf("\nEnter Address: ");
			gets(s.address);
			fflush(stdin);
			printf("\nEnter Phone Number: ");
			scanf("%s",s.phonenumber);
			fflush(stdin);
			printf("\nEnter Nationality: ");
			scanf("%s",s.nationality);
			fflush(stdin);
			printf("\nEnter Email: ");
			scanf(" %s",s.email);
			fflush(stdin);
			printf("\nEnter Period(\'x\'days): ");
			scanf("%s",s.period);
			fflush(stdin);
			printf("\nEnter Arrival date(dd/mm/yyyy): ");
			scanf("%s",s.arrivaldate);
			fwrite(&s,sizeof(s),1,temp);
		}
		else
		{
			fwrite(&s,sizeof(s),1,temp);
		}
	}
	if(k==1)
	{
		printf("\n\n THE RECORD DOESN'T EXIST.");
		fclose(temp);
		remove("temp.txt");
		fclose(f);
		printf("\n Press any key to go to main menu...");
		getch();
	}
	else
	{
		fclose(f);
		fclose(temp);
		remove("add.txt");
		rename("temp.txt", "add.txt");
		printf("\n\n YOUR RECORD IS SUCCESSFULLY EDITED.");
		printf("\n Press any key to go to main menu...");
		getch();
	}
}