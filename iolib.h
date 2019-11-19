
#include <iostream>
#include <vector>
#include <fstream>

class ioGen{

private:

	std::vector <std::string> ioStringSet;

	std::vector <char> ioCharSet;

	std::vector <char> lowerCharSet{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	std::vector <char> upperCharSet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    std::vector <char> numericalCharSet{'0','1','2','3','4','5','6','7','8','9'};

    std::vector <char> specialCharSet{'#','@','_','-','.'};

	unsigned int ioBase;


	std::vector <unsigned int> *ioCombinationAddr{nullptr};

	std::vector <unsigned int> ioCombination;

	unsigned int minLen;

	unsigned int maxLen;

	bool isIncrementable();

	bool ioIncrement();

	bool shouldAddDigit();
	
	std::vector<char> genVecFromCharSet(std::string strCharSet);

	bool isCharComb;

    bool setIncStateCalled;
    
    std::ofstream ioTmpFile;


public:

	ioGen();
	
	ioGen(unsigned int __min, unsigned int __max, std::string stdCharSet);
	
	ioGen(unsigned int __min, unsigned int __max, std::vector<char> __ioCharSet);

	ioGen(unsigned int __min, unsigned int __max, std::vector<std::string> __ioStringSet);

	bool setIncState(std::vector <unsigned int> __ioCombination); // to set the initial count state

	bool ioIncWrapper();

	bool isIncWrapper();

	void printCombination();

	void printStrCombination();

    unsigned int combinationMaxCount();

    void writeToFile();

    void closeFile();

};
