#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "attribute.h"

namespace ParseFile {

	enum class input {attribute, data, STRING, numeric, none};


	std::vector<Attr::Attribute> parseArffFile(std::string);
	std::vector<std::string> split(std::string, std::string);
	void test(std::vector<std::string>);
	input getInputType(std::string);
	std::string pruneString(std::string);
	std::vector<std::string> cleanStringVector(std::vector<std::string>);
	


}

