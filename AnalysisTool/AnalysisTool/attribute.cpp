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
			struct number n = { num, true };
			Attribute::numericCases.push_back(n);
			Attribute::initIndex++;
			return true;
		}
		else {
			struct number n = { 0, false };
			Attribute::numericCases.push_back(n);
			Attribute::initIndex++;
			return false;
		}
	}
}

void Attribute::printName() {
	cout << "Attribute name is: " << Attribute::name;
	switch (Attribute::aType) {
	case category::list:
		cout << ", type is: list" << std::endl;
		break;
	case category::numeric:
		cout << ", type is: numeric" << std::endl;
		break;
	case category::other:
		cout << ", type is: other" << std::endl;
		break;
	default:
		cout << ", type is: unknow ERROR!" << std::endl;
		break;
	}
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
				if (Attribute::numericCases[i].isFilled) {
					cout << "case " << i << ": " << Attribute::numericCases[i].value << " test: " << Attribute::numericCases[i].value + 1 << std::endl;
				}
				else {
					cout << "case " << i << ": empty" << std::endl;
				}
			}
		}
	}
}