#include <iostream>
#include <sstream>
#include "functions/CONSTANTS.h"

using namespace std;

string CONSTANTS(string Constants) {
    string ConstantsOverload = "";

    for (size_t i = 10; i < Constants.length(); ++i) {
        ConstantsOverload += Constants[i];
    }

    return "section.data\n" + ConstantsOverload;
}
