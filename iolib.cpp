

#include "iolib.h"
#include <math.h>

ioGen::ioGen()
:ioGen{2, 2, std::vector<char>{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'}}
{
	
}

ioGen::ioGen(unsigned int __min, unsigned int __max, std::string strCharSet)
:
 ioBase{static_cast<unsigned int> (genVecFromCharSet(strCharSet).size())},
 ioCombination(__min, 0), minLen{__min}, maxLen{__max}{
	 
	this->ioCharSet = genVecFromCharSet(strCharSet); //ioCharSet initialization fails, but this works good
	
	for(unsigned int num: ioCombination){std::cout << num << " , "; }
	 
	this->isCharComb = true;
	 
	ioTmpFile.open("outputFile.txt");
}


ioGen::ioGen(unsigned int __min, unsigned int __max, std::vector <char> __ioCharSet)
	:ioCharSet{__ioCharSet}, ioBase{static_cast<unsigned int> (__ioCharSet.size())}, ioCombination(__min, 0), minLen{__min}, maxLen{__max}{
    this->isCharComb = true; //this step helps us to determind how to form words during the write to file process
    
	ioTmpFile.open("outputFile.txt");
	
}

ioGen::ioGen(unsigned int __min, unsigned int __max, std::vector<std::string> __ioStringSet)
    :ioStringSet{__ioStringSet}, ioBase{static_cast<unsigned int>(__ioStringSet.size())},ioCombination(__min, 0), minLen{__min}, maxLen{__max}{
    this->isCharComb = false; //this step helps us to determind how to form words during the write to file process
    ioTmpFile.open("outputFile.txt");
}

std::vector<char> ioGen::genVecFromCharSet(std::string strCharSet){
	
	std::vector <char> finalCharSet;
	
	for(char strChar: strCharSet){
		
		switch(strChar){
			case 'l':
			case 'L': for(char setChar: this->lowerCharSet){finalCharSet.push_back(setChar);} break;
			case 'u':
			case 'U': for(char setChar: this->upperCharSet){finalCharSet.push_back(setChar);} break;
			case 'n':
			case 'N': for(char setChar: this->numericalCharSet){finalCharSet.push_back(setChar);} break;
			case 's':
			case 'S': for(char setChar: this->specialCharSet){finalCharSet.push_back(setChar);} break;
			default : break;
		}
		
	}
	
	return finalCharSet;
}

bool ioGen::setIncState(std::vector<unsigned int> __ioCombination){
	
	bool status {false};

	this->ioCombinationAddr = new std::vector<unsigned int> (__ioCombination);
	
	status = true;

	this->setIncStateCalled = true; // !important

	this->ioCombination = *(this->ioCombinationAddr); //we let ioCombination point to this new address

	return status;
}



bool ioGen::isIncrementable(){
	//let's test for incrementability.
	bool status;
	//first we check if all the digits of this->ioCombination are not (ioBase -1)
	if(this->ioCombination != std::vector <unsigned int> (this->ioCombination.size(), this->ioBase -1)){
		status = true;
	}else if (this->ioCombination == std::vector <unsigned int> (this->ioCombination.size(), this->ioBase -1)) status = false;
	else status = false;

	return status;
}

bool ioGen::ioIncrement(){
	bool status;

	if (this->isIncrementable()){

        int cursor{static_cast<int>(this->ioCombination.size()) - 1};

		while (cursor >= 0){

			if (this->ioCombination.at(cursor) < (this->ioBase - 1)){ //if the digit at the cursor is incrementable

				this->ioCombination.at(cursor) += 1;
				status = true;
				break;

			}else{

				//at this point no incrementation took place
				//but this->ioCombination is incrementable

				if(this->ioCombination.at(cursor) == (this->ioBase - 1)){
					this->ioCombination.at(cursor) = 0;

					cursor -= 1;

				}

			}

		}
	}else {
		if(this->ioCombination.size() < this->maxLen){
			this->ioCombination.insert(this->ioCombination.begin(), 1);
			for (unsigned int i = 0; i < static_cast<unsigned int>(this->ioCombination.size()); i++){
                this->ioCombination.at(i) = 0;
			}

			//this->ioIncrement();

		}else if(this->ioCombination.size() == this->maxLen) status = false;
	}

	return status;
}

bool ioGen::ioIncWrapper(){return this->ioIncrement();}

bool ioGen::isIncWrapper(){return this->isIncrementable();}


void ioGen::printCombination(){
	std::string tmpStr{""};
    if (isCharComb==true){
        for (unsigned int n: this->ioCombination){
            tmpStr += this->ioCharSet.at(n);
        }
    }else if (!isCharComb){
        for (unsigned int n: this->ioCombination){
            tmpStr += this->ioStringSet.at(n);
        }
    }
	
	std::cout << tmpStr << std::endl;
}


unsigned int ioGen::combinationMaxCount(){

    unsigned int tmpCount{0};
    unsigned int initCount{0};

    int digitPow{static_cast<int> (this->ioCombination.size()) - 1}; //holds the power of the current digit 

    for(unsigned int i = this->minLen; i <= this->maxLen; i++){
        tmpCount += std::pow(static_cast<unsigned int>(this->ioBase), static_cast<unsigned int>(i));
    }
	
    if(this->setIncStateCalled == true){
    	for(unsigned int j = 0; j <= this->ioCombination.size(); j++){
	    	if(digitPow == -1){break;}
	    	initCount += (this->ioCombination.at(j) + 1) * (std::pow (static_cast<unsigned int>(this->ioBase), static_cast<int>(digitPow)));
	    	digitPow--;
   		}

   		std::cout << "the value of the initial count is " << initCount << std::endl;

    }

    return (tmpCount) - (initCount);
}

void ioGen::writeToFile(){
    
	std::string tmpStr{""};
	std::cout << "the size of ioCharSet is " <<ioCharSet.size() << std::endl;
	std::cout << "and the ioBas is " << ioBase << std::endl;
	if(isCharComb == true){
        for (unsigned int n: this->ioCombination){tmpStr = tmpStr + this->ioCharSet.at(n);}
    }else if (isCharComb == false){
        for (unsigned int n: this->ioCombination){tmpStr = tmpStr + this->ioStringSet.at(n);}
    }
	
	//we go to a new line if the max ioCombinations is not reached
	if (this->ioCombination != std::vector<unsigned int>(this->maxLen, this->ioBase - 1)){
		this->ioTmpFile << tmpStr << "\n";
	}else{this->ioTmpFile << tmpStr;}
}

void ioGen::closeFile(){
    this->ioTmpFile.close();
}


//stop right here