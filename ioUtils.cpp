#include "ioUtils.h"

ioArgParser::ioArgParser(std::vector<std::string> __argVec){
	
	unsigned int argSize{static_cast<unsigned int>(__argVec.size())};
	
	unsigned int foundArgSize{0};
	
	std::string tmpStr{""};
	
	std::map<std::string, std::string>::iterator mapIter;
	
	std::vector<std::string> unrequiredArgs;
	
	if(__argVec.size() % 2 == 0){
		for(unsigned int counter = 0; counter < argSize; counter += 2){
			this->argMap.insert(std::make_pair(__argVec.at(counter), __argVec.at(counter + 1)));
		}
	}else{
		std::cout << "some arguments have no operands" << std::endl;
	}
	
	
	
	mapIter = this->argMap.begin(); 
	
	while(mapIter != this->argMap.end()){
		
		if     (mapIter->first == "-mn"){ foundArgSize++; }
		else if(mapIter->first == "-mx"){ foundArgSize++;}
		else if(mapIter->first == "-cs"){ foundArgSize++;}
		else if(mapIter->first == "-ch"){ foundArgSize++;}
		else if(mapIter->first == "-st"){ foundArgSize++;}
		else{
			std::cout << " <" << mapIter->first << "> " << " is not a required argument" << std::endl;
			unrequiredArgs.push_back(mapIter->first);
		}
		
		mapIter++;
	}
	
	if(foundArgSize == 3){
		if(unrequiredArgs.size() > 0){
			for(std::string argName: unrequiredArgs){this->argMap.erase(argName);} //get rid of unrequired arguments
		}
		std::cout << "needed args are all provided" << std::endl;
	}else{
		std::cout << " we expect a command of the form \n -mn 4 -mx 6 -c luns" << std::endl;
	}
	
	std::cout << "the initialization is complete" << std::endl;
}

std::string ioArgParser::setArgs(){
	std::string argSetType{""};
	
	std::map<std::string, std::string>::iterator mapIter = this->argMap.begin();
	
	while(mapIter != this->argMap.end()){
		if(mapIter->first == "-cs") {this->usingCharSet = true; argSetType += "-cs";}
		else if(mapIter->first == "-ch") {this->usingCharacters = true; argSetType += "-ch";}
		else if(mapIter->first == "-st") {this->usingStrings = true; argSetType += "-st";}
		mapIter++;
	}
	return argSetType;
}
bool ioArgParser::isNumberValid(std::string strNum){
	
	bool status{false};
	
	std::vector <bool> intStates;


	for(char tmpChar: strNum){if (tmpChar < 48 || tmpChar > 57){intStates.push_back(false);}else{intStates.push_back(true);}}

	if(std::vector<bool> (intStates.size(), true) != intStates){status = false;}else{status= true;}
	
	return status;
}


unsigned int ioArgParser::extractIntFromString(std::string numChar){
	//we reveive a pointer as an argument

	int magnitude{0}; //we'll adding each interation to this variable
	
	int digitPower{static_cast<int>(numChar.size()) - 1};
	
	for(int tmpChar: numChar){ // int was char
		//
		/*switch(tmpChar){
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
		}*/
		
		//the above switch statement is not the best approach
		
		magnitude += (tmpChar - 48) * pow(10, digitPower); digitPower--; //48 is the ascii of zero
	}

	return magnitude;
}	

int ioArgParser::deliverBoundery(std::string bounderyName){
	int result{0};
	
	if(bounderyName == "-mn" && this->isNumberValid(this->argMap["-mn"])){
		result = this->extractIntFromString(this->argMap["-mn"]);
	}else if(bounderyName == "-mx" && this->isNumberValid(this->argMap["-mx"])){
		result = this->extractIntFromString(this->argMap["-mx"]);
	}else{ result = -1; }
	
	return result;
}

std::string ioArgParser::deliverCharSet(){
	std::string charSet;
	
	if(this->usingCharSet == true) charSet = this->argMap["-cs"];
	
	return charSet;
}

std::vector<char> ioArgParser::deliverCharacters(){
	std::vector <char> tmpCharVec;
	if(this->usingCharacters == true){
		for(char tmpChar: this->argMap["-ch"]){tmpCharVec.push_back(tmpChar);}
	}
	return tmpCharVec;
}