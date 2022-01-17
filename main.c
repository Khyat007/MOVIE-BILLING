#include<stdio.h>
#include<stdlib.h>
#include"Bookingdetails.c"                          // This is an externally attached file.
#include"decleration.c"                             // This is an externally attached file.
#include<strings.h>


struct Bookingdetails person[300];
int count=0;
int id2=1000;
int main()

{
	int **seat,choice,price,selection;
	seat=(int **)calloc(101,sizeof(int *));
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  ########################  LOGIN PAGE  ########################  ");                              //This is a Password protected application.
        printf(" \n\n                 ENTER USERNAME:-");
	scanf("%s", &uname);
           printf(" \n\n               ENTER PASSWORD:-");
	scanf("%s",&pword);
printf("\n\n    ##############################################################");
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");


	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFULL");
		a++;

	}

}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");

exit(0);
		}


		system("cls");
       for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	int x;
	while(x!=5)
	{
		choice=choice1();
		switch(choice)
		{

			case 1:
				details();
				break;
			case 2:
				selection=movie();
				reservation(seat[selection-1],price,selection);
				count++;
				break;
			case 3:
				selection=cmovie();
				cancel(seat[selection-1]);
				break;
			case 4:
				x=5;
				break;
			default:
				printf("Choice not available\n");
				break;
		}
	}
}




void reservation(int *array,int price,int selection)
{
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else
				printf("*\t",i);
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please enter your name: ");                                                   // The program asks us about our details.
		scanf(" %19[^\n]%*[^\n]",&person[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&person[count].phone);
		printf("Which seat number you want? ");
		scanf("%d",&j);


    if(j<=40)
    {
     price=300 ;
    }

    else if(j>40&&j<=80)
    {
       price=400;
    }
    else if(j>80&&j<=100)
    {
       price=450;
    }
    else
    {
       printf("Invalid seat number\n");
    }

		if (j>100||j<1)
			{
				printf("Seat number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		person[count].seat=j;
		if (selection==1)
			ticket1(j,person[count].name,id2,price);
		else if (selection==2)
			ticket2(j,person[count].name,id2,price);
		else
			ticket3(j,person[count].name,id2,price);
		id2++;

}
int choice1(void)
{
	int choice;
	printf("                 Movie Ticket Billing System\n");                                                          //This is the Main interface page of our application.
	printf(" ==================================================================\n");
    printf(" ==================================================================\n");
	printf("||             1- To view reserved tickets (only admin):          ||\n");
	printf("||             2- To purchase ticket:                             ||\n");
	printf("||             3- To cancel the seat:                             ||\n");
	printf("||             4- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf(" ==================================================================\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int Cseat,i,stop;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);
	  for (i=0;i<300;i++)
	  {
	  		if(Cseat==person[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat is %d cancelled",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}
void ticket1(int choice,char name[10],int id2,int price)                                                            // This is the Movie Ticket
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------MOVIE TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : American Pie\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 29-04-2019\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
void details(void)
{
	int i;
	char pass[10],pak[10]="pass";
	printf("Enter the password to see details: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
		}
	}
	else
		printf("Entered password is wrong \n");
		system("PAUSE");
		system("CLS");

}
int movie(void)
{
	int i;
	system("cls");
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tpress 1 for American Pie\n\n");
	printf("\t\t\tpress 2 for 365 Days\n\n");
	printf("\t\t\tpress 3 for Spider-Man: No Way  Home\n");
	scanf("%d",&i);
	system("cls");
	return i;
}
void ticket2(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");                                                                                    //This is the Movie Ticket.
        printf("\t-----------------MOVIE TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : 365 Days\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 15-04-2019\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
int cmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for American Pie\n\n");
	printf("\t\t\tpress 2 for 365 Days\n\n");
	printf("\t\t\tpress 3 for Spider-Man\n");
	scanf("%d",&i);
	return i;
}
void ticket3(int choice,char name[10],int id2,int price)
{
		system("cls");                                                                                             //This is the Movie Ticket.
		printf("\n\n");
        printf("\t-----------------MOVIE TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Spider-Man: No Way  Home \n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 5-07-2019\n");
        printf("\t                                              Time      : 10:00pm\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}




