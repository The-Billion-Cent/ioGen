#include <iostream>
#include <map>
#include <vector>
#include <math.h>

class ioArgParser{
	
private:

	unsigned int argSize;
	
	std::map<std::string, std::string> argMap;
	
	bool isArgRight();
	
public:	
	ioArgParser(std::vector<std::string> __argVec);
	
};

