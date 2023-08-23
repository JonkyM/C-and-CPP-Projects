#include <iostream>
#include "AUList.h"
#include <cmath>

int main(int argc, char** argv) {	
	AUList TestList;
	AUList* NewList;
	AUList Duplicate;
	AUList Duplicate2;

	std::cout<<"Newly Created List: ";
	TestList.PrintList();
	for (int i=0; i<10; i++)
	  TestList.PutItem(100-i*10);
	std::cout<<"List after 'PutItem' calls: ";
	TestList.PrintList();
	std::cout<<"Length after 'PutItem' calls: " <<TestList.GetLength() <<std::endl;
	std::cout<<"Arithmetic mean of list: " <<TestList.getMean() <<std::endl;
	std::cout<<"Standard deviation of list: " <<TestList.getStdev() <<std::endl;
	Duplicate = TestList.DuplicateNV(6);
	std::cout<<"Duplicate list after 'DuplicateNV' call: ";
	Duplicate.PrintList();
	std::cout<<"IsFull after 'PutItem' calls? " <<TestList.IsFull() <<std::endl;
	TestList.DeleteItem(50);
	std::cout<<"List after 'DeleteItem' call: ";
	TestList.PrintList();
	std::cout<<"Arithmetic mean of list: " <<TestList.getMean() <<std::endl;
	std::cout<<"Standard deviation of list: " <<TestList.getStdev() <<std::endl;
	Duplicate2 = TestList.DuplicateNV(6);
	std::cout<<"Duplicate2 list after 'DuplicateNV' call: ";
	Duplicate2.PrintList();
	std::cout<<"IsFull after 'DeleteItem' call? " <<TestList.IsFull() <<std::endl;
	std::cout<<"Index of value 80: "<<TestList.GetItem(80)<<std::endl;
	std::cout<<"Index of value 25: "<<TestList.GetItem(25)<<std::endl;
	TestList.MakeEmpty();
	std::cout<<"List after 'MakeEmpty': ";
	TestList.PrintList();		
	return 0;
}
