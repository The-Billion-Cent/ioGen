#include <math.h>
#include <iostream>
#include "iolib.h"
#include <cstring>
#include <ctype.h>


unsigned int intMagnitudeFromChar(std::string numChar){
	//we reveive a pointer as an argument

	int magnitude{0}; //we'll adding each interation to this variable
	
	int digitPower{static_cast<int>(numChar.size()) - 1};
	
	for(char tmpChar: numChar){
		switch(tmpChar){
			case '9': magnitude += 9 * std::pow(10, digitPower); digitPower--; break;
			case '8': magnitude += 8 * std::pow(10, digitPower); digitPower--; break;
			case '7': magnitude += 7 * std::pow(10, digitPower); digitPower--; break;
			case '6': magnitude += 6 * std::pow(10, digitPower); digitPower--; break;
			case '5': magnitude += 5 * std::pow(10, digitPower); digitPower--; break;
			case '4': magnitude += 4 * std::pow(10, digitPower); digitPower--; break;
			case '3': magnitude += 3 * std::pow(10, digitPower); digitPower--; break;
			case '2': magnitude += 2 * std::pow(10, digitPower); digitPower--; break;
			case '1': magnitude += 1 * std::pow(10, digitPower); digitPower--; break;
			case '0': magnitude += 0 * std::pow(10, digitPower); digitPower--; break;
			default: std::cerr << "\n \t something unexpected just happened \n" << std::endl; break;
		}
	}

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
	
	if(argc > 1){
		if(isValidNumber(std::string(argv[1]))){
			std::cout << "the number is valid and is of magnitude " << intMagnitudeFromChar(std::string(argv[1])) << std::endl; 
			if(argc > 2){
				std::cout << "now supports more arguments" << std::endl;
			}
		}
	}

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

