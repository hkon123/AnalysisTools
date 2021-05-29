#include "attribute.h"
#include "iostream"
#include <string>
#include <sstream>

using namespace Attr;
using namespace std;



void Attribute::setValues(category inType, std::string inName) {
	Attribute::aType = inType;
	Attribute::name = inName; 
	Attribute::initIndex = 0;
}

void Attribute::initCases() {
	if (Attribute::aType == category::list || Attribute::aType == category::other) {
		cout << "data type is: strings\n";
	}
	else {
		cout << "data type is: ints\n";
	}
}

void Attribute::setTypes(std::vector<std::string> inTypes) {
	Attribute::types = inTypes;
}


bool Attribute::addCase(std::string input) {

	if (Attribute::aType == category::list || Attribute::aType == category::other) {
		Attribute::stringCases.push_back(input);
		Attribute::initIndex++;
		return true;
	}
	else {
		int num;
		stringstream ss(input);
		ss >> num;
		if (ss.eof()) {
			Attribute::numericCases.push_back(num);
			Attribute::initIndex++;
			return true;
		}
		else {
			//Attribute::numericCases.push_back(NAN);
			//Attribute::initIndex++;
			return false;
		}
	}
}

void Attribute::printName() {
	cout << "Attribute name is: " << Attribute::name << std::endl;

	if (Attribute::aType == category::list) {
		std::vector<std::string>::iterator iter = Attribute::types.begin();
		std::vector<std::string>::iterator end = Attribute::types.end();
		while (iter != end)
		{
			std::cout << "category: " << (*iter) << std::endl;
			++iter;
		}
	}
	if (Attribute::initIndex > 0) {
		for (int i = 0; i < Attribute::initIndex; i++) {
			if (Attribute::aType == category::list || Attribute::aType == category::other) {
				cout << "case " << i << ": " << Attribute::stringCases[i] << std::endl;
			}
			else {
				cout << "case " << i << ": " << Attribute::numericCases[i] << " test: " << Attribute::numericCases[i] + 1 << std::endl;
			}
		}
	}
}