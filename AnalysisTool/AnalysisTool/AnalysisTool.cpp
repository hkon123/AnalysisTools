// AnalysisTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "attribute.h"
#include <string>
#include <vector>

using namespace Attr;

int main()
{
    Attribute A;
    std::string in = "test";
    A.setValues(category::numeric, in);

    std::vector<std::string> myStrings = { "type1", "type2" };

    A.initCases();

    //A.setTypes(myStrings);

    std::cout << A.addCase("hello") << std::endl;

    std::cout << A.addCase("2.0") << std::endl;

    std::cout << A.addCase("4") << std::endl;

    A.printName();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
