#include "ioUtils.h"

ioArgParser::ioArgParser(std::vector<std::string> __argVec){
	
	unsigned int argSize{static_cast<unsigned int>(__argVec.size())};
	
	unsigned int parsedArgSize{0};
	
	unsigned int targetArgSize{0};
	
	std::string tmpStr{""};
	
	std::map<std::string, std::string>::iterator mapIter;
	
	
	for(unsigned int counter = 0; counter < argSize; counter += 2){
		this->argMap.insert(std::make_pair(__argVec.at(counter), __argVec.at(counter + 1)));
		targetArgSize+= 1;
	}
	
	
	mapIter = this->argMap.begin();
	
	while(mapIter != this->argMap.end()){
		
		std::cout << " entered e" << std::endl;
		
		if(mapIter->first == "min"){
			std::cout << "min is located" << std::endl;
		}
		
		mapIter++;
	}
	
	std::cout << "the size of our argMap is " << this->argMap.size() << std::endl;
	
	if(parsedArgSize == targetArgSize){
		//if we enter here, then everything is okay with the arguments key
		std::cout << "everything is okay with our argument keys " << std::endl;
	}
	
}

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