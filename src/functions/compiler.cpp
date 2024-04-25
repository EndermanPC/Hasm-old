#include <iostream>
#include <fstream>
#include <string>

#include "functions/compiler.h"
#include "functions/CONSTANTS.h"
#include "functions/VARIABLES.h"
#include "functions/EXECUTABLE.h"
#include "functions/EXIT.h"

using namespace std;

void compile(string fileName, string outputFileName) {
    ifstream file(fileName);
    ofstream taget("taget.asm");

    if (!file.is_open()) {
        cout << "Error: Unable to open file '" << fileName << "'." << endl;
        exit(-1);
    }

    string line;
    long lineNumber = 0;
    while (getline(file, line)) {
        lineNumber++;
        string errorChecker;

        if (line.find("EXECUTABLE ") != string::npos) {
            errorChecker = EXECUTABLE(line);
            taget << errorChecker << endl;
        } else if (line.find("VARIABLES ") != string::npos) {
            errorChecker = VARIABLES(line);
            taget << errorChecker << endl;
        } else if (line.find("CONSTANTS ") != string::npos) {
            errorChecker = CONSTANTS(line);
            taget << errorChecker << endl;
        } else if (line.find("EXIT ") != string::npos) {
            errorChecker = EXIT(line);
            if (errorChecker == "ERROR - CODE - EXIT") {
                cout << "Eror: Line (" << lineNumber << "): Exit value cannot be determined." << endl;
                cout << "      Code: "<< line << endl;
                exit(-1);
            }
            else taget << EXIT(line) << endl;
        }
    }

    file.close();
}