#include <iostream>

#include <math.h>
#include <cstring>


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