#include "MinHeap.h"
#define MAXSIZE 999
#include <string>

class PQueue {
	private:
	MinHeap items;
	public:
	PQueue(int max);	
	~PQueue();	
	void Dequeue();
	void Enqueue(CPUBenchmark newItem);    
    bool IsFull();	
	bool IsEmpty();
	void MakeEmpty();
};

