#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <string>

class ioArgParser{
	
private:

	unsigned int argSize;
	
	std::map<std::string, std::string> argMap;
	
	bool usingCharSet{false};	// is used in set args
	
	bool usingCharacters{false}; //is usend in 
	
	bool usingStrings{false}; //is used in setArgs
	
	bool isNumberValid(std::string strNum); // okay
	
	unsigned int extractIntFromString(std::string strNum);
	
	
public:

	ioArgParser(std::vector<std::string> __argVec);
	
	std::string setArgs(); //is used only in the class initialization method
	
	int deliverBoundery(std::string bounderyName); //okay
	
	std::string deliverCharSet(); 
	
	std::vector<char> deliverCharacters();
	
	//std::string deliverStringSet(); // passive and support will be implemented on ioGen v02
};

