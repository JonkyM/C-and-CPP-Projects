#define MAXSIZE 999
#include <string>

struct CPUBenchmark {
std::string cpuName;
double price; // Last seen market price, in USD($)
int cpuMark; // Multi thread CPU Mark
int threadMark; // Single thread CPU Mark
int cores; // Number of cores in the CPU
int testDate;	// Date of first benchmarck submission
};

class AUList
{
public:
  
  AUList(); // Constructor
  
  void MakeEmpty();  // Returns the list to the empty state.
    
  bool IsFull() const; //Determines whether list is full. (Precondition -- list has been initialized).  Return value of "True" indicates class is full.
  
  int GetLength() const; //Determines the number of elements in list.

  void PutItem(CPUBenchmark); //Adds the item to the list.
    
  void ResetList();  //Initializes iterator's current position for an iteration through the list.

  CPUBenchmark GetNextItem(); //Gets the next element in the list.

  bool HasNextItem();
  
  void PrintList();  //Print all elements of the list in a readable format.
  
    

private:
  int length;
  CPUBenchmark ListItems[MAXSIZE];
  int currentPos;
};

