#include <iostream>
#include "functions/VARIABLES.h"

using namespace std;

string VARIABLES(string Variables) {
    string VariablesOverload = "";

    for (size_t i = 10; i < Variables.length(); ++i) {
        VariablesOverload += Variables[i];
    }

    return "section.bss " + VariablesOverload;
}