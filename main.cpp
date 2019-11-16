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
	
	std::string argSet{inArg.setArgs()};
	std::cout << "argSet is allright and value is " << argSet << std::endl;
	
	if( argSet == "-ch"){
		std::cout << "we entered the conditional statement" << std::endl;
		
		ioGen charGen{static_cast<unsigned int> (inArg.deliverBoundery(std::string{"-mn"})),static_cast<unsigned int>(inArg.deliverBoundery(std::string{"-mx"})), inArg.deliverCharacters()};
		
		std::cout << "we managed to here" << std::endl;
		
		unsigned int maxCount = charGen.combinationMaxCount();

		std::cout << maxCount;

		charGen.writeToFile();
		
		for(unsigned int counter = 1; counter < maxCount; counter++){

				charGen.ioIncWrapper();
				charGen.writeToFile();

		}

		charGen.closeFile();
	}
	//charGen.setIncState(std::vector <unsigned int> {2,0,2,0,0,0});
	

	
	
	return 0;
}

