#include <iostream>
#include <cstring>
#include <string>
#include "functions/compiler.h"

using namespace std;

int main(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-c") == 0) {
            bool haveOutputOption = false;
            for (int j = 1; j < argc; ++j) {
                if (strcmp(argv[j], "-o") == 0) {
                    compile(argv[i + 1], argv[j + 1]);
                    haveOutputOption = true;
                    i++;
                    break;
                }
            }
            if (!haveOutputOption) {
                compile(argv[i + 1], "a.exe");
                i++;
            }
        }
    }

    return 0;
}
