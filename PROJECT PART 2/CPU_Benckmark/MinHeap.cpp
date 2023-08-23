#include "MinHeap.h"
#include <iostream>
#include <stdexcept>

void MinHeap::ReheapDown(int top, int bottom) {
  	int maxChild;
	int leftChild = top*2+1;
	int rightChild = top*2+2;
	if (leftChild > bottom) 
		return;
	else {
		if (leftChild==bottom)
			maxChild = leftChild;
		else {
			if (elements[leftChild].price >= elements[rightChild].price)
				maxChild=rightChild;
			else
				maxChild=leftChild;
		}
		if (elements[top].price > elements[maxChild].price) {
			CPUBenchmark tmp = elements[maxChild];
			elements[maxChild] = elements[top];
			elements[top] = tmp;
			ReheapDown(maxChild,bottom);
		}				
	}
}
	

void MinHeap::ReheapUp(int top, int bottom) {
  	if (bottom > top) {
    	int parent = (bottom-1) / 2;    		
    	if (elements[parent].price > elements[bottom].price) {
			//cout<<elements[parent]<<","<<elements[bottom]<<endl;
			CPUBenchmark tmp = elements[parent];
			elements[parent] = elements[bottom];
			elements[bottom] = tmp;
			
			ReheapUp(top, parent);
    	}
  	}
}


