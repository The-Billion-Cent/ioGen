#include <math.h>
#include <iostream>
#include <cstring>
#include <ctype.h>

#include "iolib.h"
#include "ioUtils.h"

int main(int argc, char *argv[]){
	
	
	std::vector <std::string> argVec;
	
	for (int count = 1; count < argc; count++){ argVec.push_back(std::string(argv[count])); }
	
	ioArgParser ioGenMainArg {argVec};
	
	std::string argSet{ioGenMainArg.setArgs()};
	
	ioGen * ioGenMainGen{nullptr};
	
	if( argSet == "-ch"){
		
		std::cout << "we entered the conditional statement" << std::endl;
		
		ioGenMainGen = new ioGen {static_cast<unsigned int> (ioGenMainArg.deliverBoundery(std::string{"-mn"})), static_cast<unsigned int>(ioGenMainArg.deliverBoundery(std::string{"-mx"})), ioGenMainArg.deliverCharacters()};
		
	}else if(argSet == "-cs"){
		std::cout << "the character set mode is activated" << std::endl;
		
		ioGenMainGen = new ioGen {static_cast<unsigned int> (ioGenMainArg.deliverBoundery(std::string{"-mn"})), static_cast<unsigned int> (ioGenMainArg.deliverBoundery(std::string{"-mx"})), std::string {ioGenMainArg.deliverCharSet()}};
	
	}
	//charGen.setIncState(std::vector <unsigned int> {2,0,2,0,0,0});
	
		
		unsigned int maxCount = (*ioGenMainGen).combinationMaxCount();
		
		(*ioGenMainGen).writeToFile();
		
		for(unsigned int counter = 1; counter < maxCount; counter++){

				(*ioGenMainGen).ioIncWrapper();
				(*ioGenMainGen).writeToFile();

		}

		(*ioGenMainGen).closeFile();

	
	
	return 0;
}

