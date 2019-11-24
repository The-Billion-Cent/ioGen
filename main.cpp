#include <math.h>
#include <iostream>

#include <iomanip>

#include <cstring>
#include <ctype.h>


#include "iolib.h"
#include "ioUtils.h"

/*we place our colour codes here*/
#define IORESET   "\033[0m"
#define IOBLACK   "\033[30m"      
#define IORED     "\033[31m"      
#define IOGREEN   "\033[32m"      
#define IOYELLOW  "\033[33m"      
#define IOBLUE    "\033[34m"      
#define IOMAGENTA "\033[35m"      
#define IOCYAN    "\033[36m"      
#define IOWHITE   "\033[37m"      
#define IOBOLDBLACK   "\033[1m\033[30m"      
#define IOBOLDRED     "\033[1m\033[31m"      
#define IOBOLDGREEN   "\033[1m\033[32m"      
#define IOBOLDYELLOW  "\033[1m\033[33m"      
#define IOBOLDBLUE    "\033[1m\033[34m"      
#define IOBOLDMAGENTA "\033[1m\033[35m"      
#define IOBOLDCYAN    "\033[1m\033[36m"      
#define IOBOLDWHITE   "\033[1m\033[37m"      

int main(int argc, char *argv[]){
	
	std::system("clear");
	
	std::vector <std::string> argVec;
	
	for (int count = 1; count < argc; count++){ argVec.push_back(std::string(argv[count])); }
	
	ioArgParser ioGenMainArg {argVec};
	
	std::string argSet{ioGenMainArg.setArgs()};
	
	ioGen * ioGenMainGen{nullptr};
	
	if( argSet == "-ch"){
		
		ioGenMainGen = new ioGen {static_cast<unsigned int> (ioGenMainArg.deliverBoundery(std::string{"-mn"})), static_cast<unsigned int>(ioGenMainArg.deliverBoundery(std::string{"-mx"})), ioGenMainArg.deliverCharacters()};
		
		(*ioGenMainGen).setIncState(std::vector<unsigned int>(ioGenMainArg.deliverBoundery(std::string{"-mn"}), static_cast<unsigned int>(ioGenMainArg.deliverCharacters().size()/ 2 )   ));
	
	}else if(argSet == "-cs"){
		std::cout << IORED << std::setw(20)<<"the character set mode is activated" << IORESET <<std::endl;
		
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

