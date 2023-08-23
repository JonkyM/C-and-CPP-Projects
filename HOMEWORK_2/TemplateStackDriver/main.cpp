#include "wfp.h"
#include <iostream>
#include <string>
int main() {
      std::cout << "Enter a string to be analyzed: ";
      std::string userEntry;
      
      getline(std::cin, userEntry);
      
      int isGood = WellFormedParExp(userEntry);
      if (isGood != -1) {
      	std::cout << "Your string is a well-formed PE. ";
       std::cout << WellFormedParExp(userEntry);
        }
	  else
	    std::cout << "Your string is not a well-formed PE.";
      return 0;
}