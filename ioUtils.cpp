#include "ioUtils.h"

ioArgParser::ioArgParser(std::vector<std::string> __argVec){
	
	unsigned int argSize{static_cast<unsigned int>(__argVec.size())};
	
	unsigned int foundArgSize{0};
	
	std::string tmpStr{""};
	
	std::map<std::string, std::string>::iterator mapIter;
	
	std::vector<std::string> unrequiredArgs;
	
	for(unsigned int counter = 0; counter < argSize; counter += 2){
		this->argMap.insert(std::make_pair(__argVec.at(counter), __argVec.at(counter + 1)));
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
		for(std::string argName: unrequiredArgs){this->argMap.erase(argName);} //get rid of unrequired arguments
	}else{
		std::cout << " we expect a command of the form \n -mn 4 -mx 6 -c luns" << std::endl;
	}
	
}
std::string ioArgParser::setArgs(){
	std::string argSetType;
	
	std::map<std::string, std::string>::iterator mapIter = this->argMap.begin();
	while(mapIter != this->argMap.end()){
		if(mapIter->first == "-cs") this->usingCharSet = true; std::string argSetType = "-cs";
		else if(mapIter->first == "-ch") this->usingCharacters = true; std::string argSetType = "-ch";
		else if(mapIter->frist == "-st") this->usingStrings = true; std::string argSetType = "-st";
		else continue;
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

int deliverBoundery(std::string bounderName){
	int result{0};
	
	if(bounderyName == "-mn" && this->isNumberValid(this->argMap["-mn"])) result = this->extractIntFromString(this->argMap["-mn"]);
	else if(bounderyName == "-mx" && this->isNumberValid(this->argMap["-mx"])) result = this->extractIntFromString(this->argMap["-mx"]);
	else result = -1;
	
	return result;
}

std::string deliverCharSet(){
	std::string charSet;
	if(this->usingCharSet == true) charSet = this->argMap["-cs"];
	
	return charSet;
}

std::vector<char> deliverCharacters(){
	std::vector <char> tmpCharVec;
	if(this->usingCharacters == true){
		for(char tmpChar: this->argMap["-ch"]){tmpCharVec.push_back(tmpChar);}
	}
	return tmpCharVec;
}