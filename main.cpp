#include <math.h>
#include <iostream>
#include <cstring>
#include <ctype.h>

#include "iolib.h"
#include "ioUtils.h"

int main(int argc, char *argv[]){
	
	
	
	std::vector <std::string> argVec;
	
	for (int count = 1; count < argc; count++){ argVec.push_back(std::string(argv[count])); }
	
	ioArgParser inArg {argVec};
	
	
	
	
	ioGen charGen{1,6,std::vector<char> {'z','i','t'}};//{1,6,std::vector<std::string> {"Ipetrade","Gaby","Gaga","@","0","1","2","3","4","5","6","7","8","9"}};
	
	//charGen.setIncState(std::vector <unsigned int> {2,0,2,0,0,0});
	

	unsigned int maxCount = charGen.combinationMaxCount();

	std::cout << maxCount;

	charGen.writeToFile();
	
	for(unsigned int counter = 1; counter < maxCount; counter++){

            charGen.ioIncWrapper();
            charGen.writeToFile();

	}

    charGen.closeFile();
	
	return 0;
}

