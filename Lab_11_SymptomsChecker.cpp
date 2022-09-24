// My name is John Kendrick Mejia.
// I made this April 25th, 2022
// My class is CSE 130 and my Lab number is no. 1 
// with the Section letter A
// This is the symptom checker program, you can enter a number 
// and the program will generate that number of people with random symptoms
// and check whether they have covid, flu, a cold, etc.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Illness //This is my base class which defines all the symptoms an individual can have
{
	public:
		
		bool fever;
		bool cough;
		bool sBreath;
		bool rNose;
		bool hAches;
		bool sneeze;
		bool fatigue;
};

class Human : public Illness //This derived class inherits all the possible symptoms from the base class
{
	private:
		int randNum; //variable used for the randomization of symptoms
	
	public:
		Human(); //constructor
		void getChecked(Human); //method used to check what illness the human may have
		
};

int numCovid = 0;  // global variables that keep track of how many
int numCold = 0;   // people have each illness. 
int numFlu = 0;
int numElse = 0;

int main()
{
	srand(time(0)); //randomness seed
	int numPatients; //variable used to store user input
	int x; //variable used in for loops
	
	cout << "\n\t  Welcome to Symptoms Checker\n"
		 << "\n\t  Guide:     * Common     + Sometimes/Rarely     - Absent\n"
		 << "\n\t+=========================================================+"
		 << "\n\t|      Symptoms       | COVID-19  |   Cold    |    Flu    |"
		 << "\n\t+=========================================================+"
		 << "\n\t|        Fever        |     *     |     +     |     *     |"
		 << "\n\t+=========================================================+"
		 << "\n\t|        Cough        |     *     |     +     |     *     |"
		 << "\n\t+=========================================================+"
		 << "\n\t| Shortness of Breath |     *     |     -     |     -     |"
		 << "\n\t+=========================================================+"
		 << "\n\t|      Runny Nose     |     +     |     *     |     +     |"
		 << "\n\t+=========================================================+"
		 << "\n\t|      Headaches      |     +     |     +     |     *     |"
		 << "\n\t+=========================================================+"
		 << "\n\t|      Sneezing       |     -     |     *     |     -     |"
		 << "\n\t+=========================================================+"
		 << "\n\t|       Fatigue       |     +     |     +     |     *     |"
		 << "\n\t+=========================================================+"
		 << "\n\n\t How many patients would you like to check: ";
	cin  >> numPatients; //user input
	
	Human *patients = new Human[numPatients+1]; // Allocates necessary memory for the array of patients used
	
	for(int i=0;i<numPatients;i++) // Loops through all objects in the array
	{                              // And checks what illness they have based on their symptoms
		patients[i].getChecked(patients[i]);
	}
	
	cout << "\t Running Symptoms Checker..."
		 << "\n\n\t+=========================================================+\n\n"
		 << "\t Symptom Checker Results: "
		 << "\n\n\t " << numCovid << " patients have symptoms of COVID-19"
		 << "\n\t " << numCold << " patients have symptoms of the Cold"
		 << "\n\t " << numFlu << " patients have symptoms of the Flu"
		 << "\n\t " << numElse << " patients may have some other illness"
		 << "\n\n\t+=========================================================+\n\n"
		 << "\t Percentage of each illness:"
		 << "\n\n\t COVID-19:\t [" << (numCovid*100/numPatients) << "%]";
		 for(x=0; x<(numCovid*100/numPatients); x++)
		 {
		 	cout << "=";                           //The for loops here are used to print out the percentage bars
		 }
	cout << "\n\t Cold:   \t [" << (numCold*100/numPatients) << "%]";
		 for(x=0; x<(numCold*100/numPatients); x++)
		 {
		 	cout << "=";
		 }
	cout << "\n\t Flu:    \t [" << (numFlu*100/numPatients) << "%]";
		 for(x=0; x<(numFlu*100/numPatients); x++)
		 {
		 	cout << "=";
		 }
	cout << "\n\t Other:  \t [" << (numElse*100/numPatients) << "%]";
		 for(x=0; x<(numElse*100/numPatients); x++)
		 {
		 	cout << "=";
		 }
	
	cout << "\n\n\t+=========================================================+\n\n"
		 << "\t REPORT COMPLETE. ENTER ANYTHING TO CLOSE THIS APPLICATION\n\n\t ";
	cin >> x;
	
	delete [] patients; //Frees the memory used for the array of objects
}

Human::Human() //Constructor used to assign each symptom of each Human a value of true or false at random
{	
	randNum = rand() % 2; // randomly generates 0 or 1, 0 = false and 1 = true
	if(randNum == 0) 
	{
		fever = false;
	}
	else if(randNum == 1)
	{
		fever = true;
	}
	
	randNum = rand() % 2;
	if(randNum == 0)
	{
		cough = false;
	}
	else if(randNum == 1)
	{
		cough = true;
	}
	
	randNum = rand() % 2;
	if(randNum == 0)
	{
		sBreath = false;
	}
	else if(randNum == 1)
	{
		sBreath = true;
	}
	
	randNum = rand() % 2;
	if(randNum == 0) 
	{
		rNose = false;
	}
	else if(randNum == 1)
	{
		rNose = true;
	}
	
	randNum = rand() % 2;
	if(randNum == 0)
	{
		hAches = false;
	}
	else if(randNum == 1)
	{
		hAches = true;
	}
	
	randNum = rand() % 2;
	if(randNum == 0) 
	{
		sneeze = false;
	}
	else if(randNum == 1)
	{
		sneeze = true;
	}
	
	randNum = rand() % 2;
	if(randNum == 0)
	{
		fatigue = false;
	}
	else if(randNum == 1)
	{
		fatigue = true;
	}
}

void Human::getChecked(Human person) // This method checks the symptoms of each person and assigns them a illness based on that
{
	if(person.fever == true && person.cough == true && 
	   person.sBreath == true && person.sneeze == false)
	{
		numCovid++; 
		
	}
	else if(person.sBreath == false &&
	        person.rNose == true && person.sneeze == true)
	{
		numCold++;
	}
	else if(person.fever == true && person.cough == true &&
	        person.hAches == true && person.fatigue == true &&
			person.sBreath == false && person.sneeze == false)
	{
		numFlu++;
	}
	else
	{
		numElse++;
	}
	//The if else statements incrememnt the counter for an illness 
	//if the symptoms match the illness
}
