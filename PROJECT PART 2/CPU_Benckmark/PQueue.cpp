#include "PQueue.h"
#include <string>
#include <iostream>

PQueue::PQueue(int max) {
	items.maxItems = max;
	items.elements = new CPUBenchmark[max];
	items.numElements = 0;
}

PQueue::~PQueue() {
	delete [] items.elements;
}

void PQueue::Dequeue() {
	if (items.numElements == 0)
		throw;
	else {
		CPUBenchmark item = items.elements[0];
		items.elements[0] = items.elements[items.numElements-1];
		items.numElements--;
		items.ReheapDown(0,items.numElements-1);
		std::cout<< "Element Num " << items.numElements+1 << ": " <<item.cpuName<<", "<<item.price<<", "
		<<item.cpuMark<<", "<<item.threadMark<<", "<<item.cores<<", "<<item.testDate<<std::endl;
	}
}

void PQueue::Enqueue(CPUBenchmark newItem) {
	if (items.numElements == items.maxItems)
		throw;
	else {
		items.numElements++;
		items.elements[items.numElements-1] = newItem;
		items.ReheapUp(0,items.numElements-1);
	}
}            

bool PQueue::IsFull() {
	return items.numElements == items.maxItems;
}

bool PQueue::IsEmpty() {
	return items.numElements == 0;
}

void PQueue::MakeEmpty() {
	items.numElements=0;
}

