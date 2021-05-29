#include "ParseFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "attribute.h"

using namespace std;

namespace parseFile {

	std::vector<Attr::Attribute> parseArffFile(std::string filePath) {
		std::vector<Attr::Attribute> data;

		ifstream aFile;
		aFile.open(filePath);


	}

}
