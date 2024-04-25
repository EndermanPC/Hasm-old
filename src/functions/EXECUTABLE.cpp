#include <iostream>
#include "functions/EXECUTABLE.h"

using namespace std;

string EXECUTABLE(string Executable) {
    string ExecutableOverload = "";

    for (size_t i = 11; i < Executable.length(); ++i) {
        ExecutableOverload += Executable[i];
    }

    return "section.text " + ExecutableOverload;
}