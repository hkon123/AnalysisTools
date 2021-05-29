#pragma once
#include <string>
#include <vector>

namespace Attr
{
	enum class category { list, numeric, other };

	struct number {
		int value;
		bool isFilled;
	};

	class Attribute {
		category aType;
		std::vector<std::string> types;
		std::string name;
		int numCases;
		std::vector<number> numericCases;
		std::vector<std::string> stringCases;
		int initIndex;

	public:
		void setValues(category, std::string);
		void initCases();
		bool addCase(std::string);
		void printName();
		void setTypes(std::vector<std::string>);
	};

}

