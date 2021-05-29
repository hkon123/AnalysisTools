#include "ParseFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "attribute.h"

using namespace std;

namespace ParseFile {

	std::vector<Attr::Attribute> parseArffFile(std::string filePath) {
		std::vector<Attr::Attribute> data;
		std::string line;
		std::vector<std::string> reducedLine;
		std::vector<std::string> subLine;
		bool dataFlag = false;
		
		ifstream aFile;
		aFile.open(filePath);
		if (aFile.is_open()) {
			while (getline(aFile, line)) {
				reducedLine = split(line, " ");
				if (!reducedLine.empty()) {
					if (dataFlag) {
						//TODO add cases to attributes
						subLine = split(line, ",");
						for (int i = 0; i < subLine.size(); i++) {
							data.at(i).addCase(pruneString(subLine.at(i)));
						}
					}
					else {
						switch (getInputType(reducedLine.at(0))) {
						case input::attribute:
							//test(reducedLine);
							switch (getInputType(reducedLine.at(2))) {
							case input::STRING:
								//create Attribute object in data with other as typy
								data.push_back(Attr::Attribute());
								data.back().setValues(Attr::category::other, reducedLine.at(1));
								//data.back().printName();
								break;
							case input::numeric:
								//create Attribute object in data with numeric as type
								data.push_back(Attr::Attribute());
								data.back().setValues(Attr::category::numeric, reducedLine.at(1));
								//data.back().printName();
								break;
							default:
								//create Attribute object in data with list as type
								data.push_back(Attr::Attribute());
								data.back().setValues(Attr::category::list, reducedLine.at(1));
								subLine = split(line, "{");
								subLine = split(subLine.at(1), "}");
								subLine = split(subLine.at(0), ",");
								data.back().setTypes(cleanStringVector(subLine));
								//data.back().printName();
								break;
							}
							break;
						case input::data:
							dataFlag = true;
							break;
						default:
							//you found a comment
							break;
						}
					}
				}
			}
			aFile.close();
		}
		return data;
	}

	std::vector<std::string> split(std::string inString, std::string del) {
		std::string s = inString;
		std::string delimiter = del;
		std::vector<std::string> output;
		size_t pos = 0;
		std::string token;

		while ((pos = s.find(delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			output.push_back(token);
			s.erase(0, pos + delimiter.length());
		}
		output.push_back(s);
		return output;
	}

	void test(std::vector<std::string> inArray) {
		for (int i = 0; i < inArray.size(); i++) {
			cout << inArray.at(i) << std::endl;
		}
	}
	
	input getInputType(std::string inString) {
		if (inString.compare(std::string("@attribute")) == 0) {
			return input::attribute;
		}
		else if (inString.compare(std::string("@data")) == 0) {
			return input::data;
		}
		else if (inString.compare(std::string("STRING")) == 0) {
			return input::STRING;
		}
		else if (inString.compare(std::string("numeric")) == 0) {
			return input::numeric;
		}
		else {
			return input::none;
		}
	}

	std::string pruneString(std::string inString) {
		inString.erase(std::remove_if(inString.begin(), inString.end(), ::isspace), inString.end());
		return inString;
	}

	std::vector<std::string> cleanStringVector(std::vector<std::string> inArray) {
		for (int i = 0; i < inArray.size(); i++) {
			inArray.at(i) = pruneString(inArray.at(i));
		}
		return inArray;
	}
}
