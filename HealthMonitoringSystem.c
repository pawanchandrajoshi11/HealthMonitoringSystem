#include<stdio.h>   /*stands for Standard Input Output. It has the information related to input/output functions.*/
#include<stdlib.h>   /*is the header of the general purpose standard library of C programming language which includes 
					functions involving memory allocation, process control, conversions and others.*/
/*#include<windows.h> /*Windows-specific header file for the C and C++ programming languages which contains declarations for all of the 
					functions in the Windows API, all the common macros used by Windows programmers, and all the data types used by 
					the various functions and subsystems*/
#include<conio.h>   /*stands for console input and output header file. It is a header file used in old MS-DOS compilers to
					 create text user interfaces*/

int main()
{
//		Password
	int password, x=3;
	char name[100], gender[10], age[20], number[20];
	system("color 0D");	

	while (x)
	{
		printf("\nEnter the password: ");
		scanf("%d",&password);	
		
		if (password==1234)
		{
			printf("\nCorrect password\n");
			break;
		}
		else
		{
			system("color 4");
			printf("\nWrong password, try another\n");
			--x;
		if(x==0)
			exit(0);       
		}
   }


//		MENU

	system("color 0B");
	int choice,a;
	system("cls");
	while(1)
	{
		printf("\nHello,\n\nChoose the suitable option:\n");
		printf("\n1. Record of patient");
		printf("\n2. Patient history");
		printf("\n3. COVID News");
		printf("\n4. Helpline information");
		printf("\n5. Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)									//nested switch cases
		{
			case 1:
				printf("\n1. Add a Record\n");
				printf("2. Back to Main Menu\n");
				printf("\n\nEnter your choice: ");
				scanf("%d",&a);
				switch (a)
				{
				case 1:
					printf("name: ");
					scanf("%s",&name);
					printf("age: ");
					scanf("%s",&age);
					printf("gender: ");
					scanf("%s",&gender);
					printf("number: ");
					scanf("%s",&number);
                    printf("\n");
			        FILE * fptr = fopen("Record.dat","a");
			        fprintf(fptr,"Record:-\n Name: %s \n Age: %s \n Gender: %s \n Number: %s \n\n",&name,&age,&gender,&number); 
			        fclose(fptr);
					break;
								
				case 2:
					break;
				default:printf("invalid input\n");
				}
				break;
			case 2:
				system("cls");
				printf("\nCase 2\n\n");
				char line[500];
				FILE * fpointer = fopen("Record.dat","a+");
				while (!feof(fpointer))
				{
					fgets(line, 500, fpointer);
					printf("%s",line);				
				}
				fclose(fpointer);
				printf("\n\nPress enter to go back...");
				getch();
				break;                                     
			case 3:
				printf("COVID News\n");
				system("START https://covid19.who.int/");
				break;
			case 4:
				printf("Helpline information\n");
				system("START https://indianhelpline.com/DELHI-HELPLINE-NUMBERS/");
				break;
			case 5:exit(0);
			default:printf("invalid input\n");
		}
		system("cls");
	}
}