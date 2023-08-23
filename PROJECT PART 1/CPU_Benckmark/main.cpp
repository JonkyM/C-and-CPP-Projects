#include "AUList.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

AUList csvtoAUList(string csvfile) { //convert a csv file to a list structure
    AUList retCPUList;
	ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
	getline(ReadFile, line); //throw away the first line (column names)
    while (getline(ReadFile,line)) {        
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        CPUBenchmark newrec;
		while(getline(ss, curvalue, ',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            	case 0: newrec.cpuName = curvalue; break;
                case 1: newrec.price=stod(curvalue); break;
            	case 2: newrec.cpuMark=stoi(curvalue); break;
            	case 3: newrec.threadMark=stoi(curvalue); break;
                case 4: newrec.cores=stoi(curvalue); break;
            	case 5: newrec.testDate=stoi(curvalue); break;
			}
            fielditer++;
        }
        retCPUList.PutItem(newrec);
    }
    return retCPUList;
}

int main(int argc, char** argv) {
	AUList CPUBenchmarkData=csvtoAUList("CPU_benchmark_v4.csv");
	CPUBenchmarkData.PrintList(); //Print the data record-by-record
}
    
