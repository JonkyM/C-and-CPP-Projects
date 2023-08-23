#include <string>

struct CPUBenchmark {
std::string cpuName;
double price; // Last seen market price, in USD($)
int cpuMark; // Multi thread CPU Mark
int threadMark; // Single thread CPU Mark
int cores; // Number of cores in the CPU
int testDate;	// Date of first benchmarck submission
};

struct MinHeap {
	CPUBenchmark* elements;   // Array to be allocated dynamically
	int numElements; // Current # elements in heap
	int maxItems; // Max #elements in heap	
	void ReheapDown(int top, int bottom);
	void ReheapUp(int top, int bottom);
};
