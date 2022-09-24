// I made this February 8th, 2022
// My class is CSE 130 and my Lab number is no. 1 
// with the Section letter A
// This program is supposed to emulate a calculator BUT IT USES FUNCTIONS NOW!!!!
// its going to have 9 different options
// Those being addition, subtraction, multiplication, division, modulus, test for prime
// Factorial, power, and an extra function by me

#include <stdio.h>
#include <stdlib.h>

void addFunction();
void subFunction();
void multFunction();         // Function prototypes
void divsFunction();
void modFunction();
void prmFunction();                     // More function prototypes
int fctFunction(int);
float powFunction(float, int);
int oddFunction(int);


int main()
{
	
	int selection;           // used for switch statements
	float fNum1, fNum2;      // used for operations that need floats
	int iNum1, iNum2;        // used for operations that need ints
	int prime_check;         // used in the prime function
	int prime_counter = 0;   // used in the prime function
	int fct_num;             // used in the factorial function
	int fct_mem = 1;         // used in the factorial function
	int pow_count;           // used in the power function
	float pow_result;        // used in the power function
	int odd_arr[10000];      // array used to store list of odd numbers
	int odd_count = 0;		 // used in the odd function
	int odd_test;            // used in the odd function
	int print;               // used to print each value stored in the array in case 9
	
// Here im just defining the variables I plan to use for the calculator
// I define 2 numerical values as integers for the modulus operation, and I define
// 2 numerical values as floatpoint numbers for everything 


void addFunction() // sum function definition
{
	printf("\n You selected Addition!");
	printf("\n\n Enter your first number: ");
	scanf("%f", &fNum1);
	printf(" Enter your second number: ");
	scanf("%f", &fNum2);
	printf("\n\n\t %.2f + %.2f = %.2f\n\n", fNum1, fNum2, fNum1+fNum2);
}

void subFunction() // subtraction function definition
{
	printf("\n You selected Subtraction!");
	printf("\n\n Enter your first number: ");
	scanf("%f", &fNum1);
	printf(" Enter your second number: ");
	scanf("%f", &fNum2);
	printf("\n\n\t %.2f - %.2f = %.2f\n\n", fNum1, fNum2, fNum1-fNum2);
}

void multFunction() // multiplication function definition
{
	printf("\n You selected Multiplication!");
	printf("\n\n Enter your first number: ");
	scanf("%f", &fNum1);
	printf(" Enter your second number: ");
	scanf("%f", &fNum2);
	printf("\n\n\t %.2f x %.2f = %.2f\n\n", fNum1, fNum2, fNum1 * fNum2);
}

void divsFunction() // division function definition
{
	printf("\n You selected Division!");
	printf("\n\n Enter your first number: ");
	scanf("%f", &fNum1);
	printf(" Enter your second number: ");
	scanf("%f", &fNum2);
	if(fNum2 == 0)
	{
		printf("\n\n CANT DIVIDE BY ZERO \n\n");
	}
	else
	printf("\n\n\t %.2f / %.2f = %.2f\n\n", fNum1, fNum2, fNum1 / fNum2);
}

void modFunction() // modulo function definition
{
	printf("\n You selected Modulus!");
	printf("\n\n Enter your first number (ONLY INTEGERS): ");
	scanf("%d", &iNum1);
	printf(" Enter your second number (ONLY INTEGERS): ");
	scanf("%d", &iNum2);
	printf("\n\n\t %d modulo %d = %d\n\n", iNum1, iNum2, iNum1 % iNum2);
}

void prmFunction() // prime number testing function definition
{
	printf("\n You selected Check if prime!");
	printf("\n\n Enter number that will be tested (ONLY INTEGERS): ");
	scanf("%d", &iNum1);
	for (prime_check = 1; prime_check <= iNum1; prime_check++ ) // for loop that ill be using to evaluate whether prime or not
	{							
		if(iNum1 % prime_check == 0)
		{
			prime_counter++;
		}
	}
	if (prime_counter == 2)
	{
		printf("\n\n\t  %d IS A PRIME NUMBER\n\n", iNum1);
	}
	else
	{
		printf("\n\n\t  %d IS NOT A PRIME NUMBER\n\n", iNum1);
	}
	prime_counter = 0;
}

int fctFunction() // factortial function definition
{
	for(fct_num = 1; fct_num <= iNum1; fct_num++)
	{
		fct_mem = fct_mem * fct_num;
	}
	return fct_mem;
	
}

float powFunction() // power function definition
{
	pow_result = fNum1;
	for(pow_count = 1; pow_count < iNum1; pow_count++)
	{
		pow_result = pow_result * fNum1;
	}
	return pow_result;
}

int oddFunction() // function that gives n number of odd integers 
{
	for(odd_test = 1; odd_count < iNum1; odd_test++)
	{
		if(odd_test % 2 != 0) //if the number is odd it will preform the following steps
		{
			odd_count++;
			odd_arr[odd_count] = odd_test;  //assigns each odd number to its spot in the array 
		} 
		else 
			continue;
	}
	odd_count = 0; //resets the counter
}

	do
	{
		printf("\n Welcome to the super FUN calculator menu!!!");
		printf("\n What operation do you want to do (ONLY ENTER INTEGERS):");
		printf("\n\n\t (1) Addition");
		printf("\n\t (2) Subtraction");
		printf("\n\t (3) Multiplication");
		printf("\n\t (4) Division");
		printf("\n\t (5) Modulus");
		printf("\n\t (6) Check if prime");
		printf("\n\t (7) Factortial");
		printf("\n\t (8) Power");
		printf("\n\t (9) Odd number list");
		printf("\n\t (0) Exit Calculator");
		printf("\n\n Enter your selection: ");
		scanf("%d", &selection);
		
		if(selection >= 0 && selection < 10)     //if-else statement to check if input is valid
		{
		
		switch (selection)
		{
			case 1:
				addFunction();                   //for cases 1-6 I just reused my code 
				continue;                        //from last week and put them into functions
			                
			case 2:
				subFunction();
				continue;
				
			case 3:
				multFunction();
				continue;
				
			case 4:
				divsFunction();
				continue;
		
			case 5:
				modFunction();
				continue;
				
			case 6:
				prmFunction();
				continue;
			
			case 7:
				printf("\n You selected Factorial!");     //code for 7-9 was built from scratch
	            printf("\n\n Enter your number: ");
	            scanf("%d", &iNum1);
	            printf("\n\n Factorial(%d) = %d \n\n",iNum1, fctFunction(iNum1));
	            fct_mem = 1; // resets the variable back to 1
				continue;
				
			case 8:
				printf("\n You selected Power!");
	            printf("\n\n Enter your number: ");
	            scanf("%f", &fNum1);
	            printf(" Enter your exponent (ONLY INTEGERS): ");
	            scanf("%d", &iNum1);
	            printf("\n\n %.2f^%d = %.2f \n\n",fNum1, iNum1, powFunction(fNum1, iNum1));
	            continue;
	            
	        case 9:
	        	printf("\n You selected Odd number list!");
	            printf("\n\n Enter the amount of odd numbers you want (ONLY INTEGERS): ");
	            scanf("%d", &iNum1);
	            printf("\n\n the first %d odd numbers are: ", iNum1);
	            oddFunction(iNum1);
	            for(print = 1; print <= iNum1; print++)
	            {
	            	printf("%d ", odd_arr[print]);
	            }
	            printf("\n\n");
	            continue;
	        
		}
		
		}
		else
		{
			printf("\n\n\t INVALID INPUT \n\n");
			selection = 0;
			break;
		}
	}
	while(selection != 0);
	printf ("\n\n\t Good Bye!!\n\n");
	return 0; 
}
