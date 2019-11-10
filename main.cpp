#include <math.h>
#include <iostream>
#include "iolib.h"
#include <cstring>
#include <ctype.h>


unsigned int intMagnitudeFromChar(char *strAddr[]){
	//we reveive a pointer as an argument

	int magnitude; //we'll adding each interation to this variable

	// if we reach this part of the function

	return magnitude;
}	

bool isValidNumber(std::string strNum){ 
	
	bool status{false};
	
	std::vector <bool> intStates;


	for(char a: strNum){if (a < 48 || a > 57){intStates.push_back(false);}else{intStates.push_back(true);}}

	if(std::vector<bool> (intStates.size(), true) != intStates){status = false;}else{status= true;}

	return status;

}

int main(int argc, char *argv[]){

	if(isValidNumber(std::string(argv[1]))){std::cout << "the number is valid" << std::endl;}
	

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

