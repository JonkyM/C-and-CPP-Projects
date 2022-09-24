// I made this March 24th, 2022
// My class is CSE 130 and my Lab number is no. 1 
// with the Section letter A
// This program is supposed to serve as a phonebook 
// There will be 9 main functions in the program, one to add a friend 
// another one to delete a friend, and so on.
// This version will have the extra functionality of saving the list of names as a file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// the code bellow creates a data type and structure for each entry
typedef struct contact
{
	char fName[25];
	char lName[25];
	char pNumber[15];
} entry;

void addFriend(entry *,entry *,int *,int *);                    //prototype for add friend function
void removeFriend(entry *, char [], char [], int, int, int*);   //prototype for remove friend function
void showBook(entry *,int,int);		                            //prototype for print full phonebook
void sortNames(entry *, int);                                   //prototype for the name sorting function
void findNum(entry *, char [], char [], int, int);				//prototype for function that searches for phone number
void rCallFriend(entry *, int);                                 //prototype for function that calls random person
void delEveryone(entry *, entry *, int *);                      //prototype for function that deletes everyone
void saveFile(entry *, int, FILE *);                            //prototype for function that saves files
void openFile(entry *,FILE *);                                  //prototype for function that opens files

int main()
{
	int cNum = 0;                                                     // to keep track of how many contacts there are in the phonebook
	float selection;                                                  // user selection, chose float so i can later typecast into an integer
	int x;															  // used in some for-loops
	entry *arrayOfContacts = (entry *) calloc(1, sizeof(entry));	  // gives memory for one entry
	entry *temp;                                                      // temporary variable for realloc
	char matchFn[25];
	char matchLn[25];	                                              // matchFn and Ln used for the delete feature
	int del;                                                          // int used in the deletion for-loop
	srand(time(NULL));												  // seeds the random num generator for the random call
	FILE * pWrite;
	FILE * pRead;

	do
	{
		int re = cNum+2; //Number used in the reallocation function
		printf("\n Welcome to the super awesome phonebook!!!");
		printf("\n What do you want to do (ONLY ENTER INTEGERS):");
		printf("\n\n\t (1) Add friend");
		printf("\n\t (2) Delete Friend");
		printf("\n\t (3) Show phonebook");
		printf("\n\t (4) Sort names");
		printf("\n\t (5) Search for number");
		printf("\n\t (6) Call random friend");
		printf("\n\t (7) Delete everyone");
		printf("\n\t (8) Save File");
		printf("\n\t (9) Open File");
		printf("\n\t (0) Exit phonebook");
		printf("\n\n Enter your selection: ");
		scanf("%f", &selection);
		if(selection >= 0 && selection < 10)     //if-else statement to check if input is valid
		{
			switch((int)selection) //Here I typecast the float into an integer to avoid infinite looping bugs
			{
				case 1:
					addFriend(arrayOfContacts,temp,&cNum,&re);
					continue;
				
				case 2:
					removeFriend(arrayOfContacts,matchFn,matchLn,x,del,&cNum);
					continue;
				
				case 3:
					showBook(arrayOfContacts,x,cNum);
					continue;
					
				case 4:
					sortNames(arrayOfContacts,cNum);
					printf("\n");
					continue;
					
				case 5:
					findNum(arrayOfContacts,matchFn,matchLn,x,cNum);
					continue;
				
				case 6:
					rCallFriend(arrayOfContacts,cNum);
					continue;
					
				case 7:
					delEveryone(arrayOfContacts, temp,&cNum);
					continue;
					
				case 8:
					saveFile(arrayOfContacts, cNum, pWrite);
					continue;
					
				case 9:
					openFile(arrayOfContacts, pRead);
					continue;
			}
		}
		else
		{
			printf("\n\n\t INVALID INPUT \n\n");
		}
		
	}
	while(selection != 0);
	free(arrayOfContacts);
	printf("\n\n\tSee Ya Later!!\n\n ");
	return 0;
}

void showBook(entry * arrayOfContacts,int x,int cNum) //function def to print full phonebook
{
	printf("\n == Full List of Contacts == \n\n");
	if(cNum == 0)
	{
		printf("You have no friends... :(\n");
	}
	else
	{
		for(x = 0; x < cNum; x++)
		{
			printf("\n\t%s %s %s",arrayOfContacts[x].fName,arrayOfContacts[x].lName,arrayOfContacts[x].pNumber);
		}
		printf("\n\n");
	}
}

void addFriend(entry * arrayOfContacts, entry * temp, int *cNum, int *re)
{
	printf("\n == Enter contact information == ");
	printf("\n\n\tFirst Name: ");
	scanf("%s", arrayOfContacts[*cNum].fName);
	printf(" \tLast Name: ");
	scanf("%s", arrayOfContacts[*cNum].lName);
	printf(" \tPhone number: ");
	scanf("%s", arrayOfContacts[*cNum].pNumber);
	printf("\n  *CONTACT ADDED SUCCESSFULLY!*\n ");
	temp = realloc(arrayOfContacts, *re * sizeof(entry)); //reallocates necessary memory for the current amount of contacts plus 1 extra 
	if ( temp == NULL ) 
	{
		printf("\n Out of memory!\n");
	}
	else
		arrayOfContacts = temp;
		*cNum += 1;  //this increases cNum which is used to keep track of the number of contacts
}

void removeFriend(entry * arrayOfContacts, char matchFn[], char matchLn[], int x, int del, int *cNum)
{
	int match = 0; // Keeps track of match numbers
	printf("\n== Enter info of contact to delete ==");
	printf("\n\n\tFirst Name: ");
	scanf("%s", matchFn);
	printf(" \tLast Name: ");
	scanf("%s", matchLn);
	for(x = 0; x < *cNum; x++)
	{
		if (strcmp(matchFn, arrayOfContacts[x].fName) == 0 && strcmp(matchLn, arrayOfContacts[x].lName) == 0) //only becomes true if the names inputted match a name in the phonebook
		{
			printf("\n  *THERE IS A MATCH, USER DELETED* \n");
			for(del = x; del< *cNum; del++) 
			{
				arrayOfContacts[del] = arrayOfContacts[del+ 1]; //Moves all array elements after the contact that is to be deleted 
			}													//down by one, essentially overwriting the element that was to be deleted.
			match += 1;
			*cNum -= 1; //Lowers the num used to keep
			            //Track of contact count
		}
	}
	if (match == 0) // Only prints if name didnt match with anything
	{
		printf("\n          *NO MATCH FOUND* \n");
	}
}

void findNum(entry * arrayOfContacts, char matchFn[], char matchLn[], int x, int cNum)
{
	int match = 0; //Keeps count of how many matches there have been
	printf("\n== Enter name to find phone number ==");
	printf("\n\n\tFirst Name: ");
	scanf("%s", matchFn);
	printf(" \tLast Name: ");
	scanf("%s", matchLn);
	for(x = 0; x < cNum; x++)
	{
		if (strcmp(matchFn, arrayOfContacts[x].fName) == 0 && strcmp(matchLn, arrayOfContacts[x].lName) == 0) //only becomes true if the names inputted match a name in the phonebook
		{
			printf("\n          *THERE IS A MATCH* ");
			printf("\n\n    %s's phone number is %s\n",arrayOfContacts[x].fName,arrayOfContacts[x].pNumber);  //Prints name and phone number
			match += 1;
		}
	}
	if (match == 0) // Only prints if name didnt match with anything
	{
		printf("\n          *NO MATCH FOUND* \n");
	}
}

void rCallFriend(entry * arrayOfContacts, int cNum)
{
	printf("\n == Call a random friend == \n\n");
	if(cNum == 0)
	{
		printf("You have no friends to call... :(\n");
	}
	else
	{
		int rCall;
		rCall = (rand() % cNum);
		printf(" Calling %s %s...  \n",arrayOfContacts[rCall].fName,arrayOfContacts[rCall].lName);  
	}
}

void delEveryone(entry * arrayOfContacts, entry * temp, int *cNum)
{
	printf("\n == DELETING EVERYONE == \n");
	temp =  realloc(arrayOfContacts, 1 * sizeof(entry));
	if ( temp == NULL ) 
	{
		printf("\n Out of memory!\n");
	}
	else
	{
		arrayOfContacts = temp;
		*cNum = 0;
	}
}

void sortNames(entry * arrayOfContacts, int cNum)
{
	char sorter[30];
	char sorterLname[30];
	char sorterPnum[30];
	int x = 0, y;
	printf("\n == Sorted list of names alphabetically by first name == \n");
	if(cNum == 0)
	{
		printf("\nYou have no friends to sort... :(");
	}
	for(x = 0;x < cNum-1;x++)
	{
		for(y = x + 1;y < cNum;y++ )
		if(strcmp(arrayOfContacts[x].fName,arrayOfContacts[y].fName) > 0)
		{
			strcpy(sorter,arrayOfContacts[x].fName); 
			strcpy(sorterLname,arrayOfContacts[x].lName);
			strcpy(sorterPnum,arrayOfContacts[x].pNumber);
			strcpy(arrayOfContacts[x].fName,arrayOfContacts[y].fName);
			strcpy(arrayOfContacts[x].lName,arrayOfContacts[y].lName);
			strcpy(arrayOfContacts[x].pNumber,arrayOfContacts[y].pNumber);
			strcpy(arrayOfContacts[y].fName,sorter);
			strcpy(arrayOfContacts[y].lName,sorterLname);
			strcpy(arrayOfContacts[y].pNumber,sorterPnum);
			// here I did the strcpy for each part of the structure
			// that way the number and last name stays matched with
			// the correct first name
		}
	}
	for(x = 0;x < cNum;x++)
	printf("\n\t%s %s %s",arrayOfContacts[x].fName,arrayOfContacts[x].lName,arrayOfContacts[x].pNumber);
}

void saveFile(entry * arrayOfContacts, int cNum, FILE * pWrite)
{
	int choice;
	char FileName[30];
	int x;
	
	printf("\n == Do you want to save as a custom name file? == ");
	printf("\n    (1) Yes ");
	printf("\n    (2) No");
	printf("\n    Selection: ");
	scanf("%d",&choice);
	if(choice == 1)
	{
		printf(" Enter the name for your file ending with .dat:\n ");
		scanf("%s", FileName);
		pWrite = fopen(FileName,"w");
		if(pWrite != NULL)
		{
			for(x = 0; x < cNum; x++)
			{
				fprintf(pWrite, "%s %s %s \n",arrayOfContacts[x].fName,arrayOfContacts[x].lName,arrayOfContacts[x].pNumber);
			}
			fclose(pWrite);
			printf("\n == Your contacts have been saved to the custom path!! == \n");
		}
		else
		{
			printf("\n There has been an error saving your file... \n");
		}
	}
	else if(choice == 2)
	{
		pWrite = fopen("phone_book.dat","w");
		if(pWrite != NULL)
		{
			for(x = 0; x < cNum; x++)
			{
				fprintf(pWrite, "%s %s %s \n",arrayOfContacts[x].fName,arrayOfContacts[x].lName,arrayOfContacts[x].pNumber);
			}
			fclose(pWrite);
			printf("\n == Your contacts have been saved to the default path!! == \n");
		}
		else
		{
			printf("\n There has been an error saving your file... \n");
		}
	}
	else
	{
		printf("\n == INVALID SELECTION == \n");
	}
}

void openFile(entry * arrayOfContacts, FILE * pRead)
{
	int choice;
	char FileName[30];
	int x = 0;
	
	printf("\n == Do you want to open a custom file? == ");
	printf("\n    (1) Yes ");
	printf("\n    (2) No");
	printf("\n    Selection: ");
	scanf("%d",&choice);
	if(choice == 1)
	{
		printf(" Enter the name of the file you want to open:\n ");
		scanf("%s", FileName);
		pRead = fopen(FileName,"r");
		if(pRead != NULL)
		{
			printf("\n == Full List of Contacts in %s == \n\n", FileName);
			for(x = 0; !feof(pRead); x++)
			{
				fscanf(pRead, "%s %s %s",arrayOfContacts[x].fName,arrayOfContacts[x].lName,arrayOfContacts[x].pNumber);
				if (!feof(pRead))
				{
					printf("\n\t%s %s %s",arrayOfContacts[x].fName,arrayOfContacts[x].lName,arrayOfContacts[x].pNumber);
				}
			}
			printf("\n");
		}
		else
		{
			printf("\n There has been an error opening your file... \n");
		}
	}
	else if (choice == 2)
	{
		pRead = fopen("phone_book.dat","r");
		if(pRead != NULL)
		{
			printf("\n == Full List of Contacts in default path == \n\n");
			for(x = 0; !feof(pRead); x++)
			{
				fscanf(pRead, "%s %s %s",arrayOfContacts[x].fName,arrayOfContacts[x].lName,arrayOfContacts[x].pNumber);
				if (!feof(pRead))
				{
					printf("\n\t%s %s %s",arrayOfContacts[x].fName,arrayOfContacts[x].lName,arrayOfContacts[x].pNumber);
				}
			}
			printf("\n");
		}
		else
		{
			printf("\n There has been an error opening your file... \n");
		}
	}
	else
	{
		printf("\n == INVALID SELECTION == \n");
	}
}

// FIXED THE CODE AND TURNED IT INTO USSING FUNCTIONS. IM SO FLIPPING COOL 
