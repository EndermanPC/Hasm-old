#include <iostream>
#include "functions/EXIT.h"

using namespace std;

string EXIT(string EXITCODE) {
    string EXITOverload = "";

    for (size_t i = 5; i < EXITCODE.length(); ++i) {
        if (!isdigit(EXITCODE[i])) {
            return "ERROR - CODE - EXIT";
        }
        EXITOverload += EXITCODE[i];
    }
    
    if (EXITOverload != to_string(0))
        return "mov eax, 1\nmov ebx, " + EXITOverload + "\nint 0x80";
    else return "mov eax, 1\nmov ebx, ebx\nint 0x80";
}
