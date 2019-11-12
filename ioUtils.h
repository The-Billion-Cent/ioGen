#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <string>

class ioArgParser{
	
private:

	unsigned int argSize;
	
	std::map<std::string, std::string> argMap;
	
	bool isArgValid();
	
	bool isNumberValid();
	
	int argNumber();
	
public:

	ioArgParser(std::vector<std::string> __argVec);
	
};

