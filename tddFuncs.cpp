#include <iostream>
#include <string>
#include "tddFuncs.h"

using namespace std;

void assertEquals(string expected, string actual, string message) {
    if (expected == actual) {
        cout << "PASSED: " << message << endl;
    }
    else {
        cout << "   FAILED: " << message << endl
            << "    Expected:[\n" << expected
            << "] actual = [\n"
            << actual << "]\n" << endl;
    }
}

void assertEquals(int expected, int actual, string message) {
    if (expected == actual) {
        cout << "PASSED: " << message << endl;
    }
    else {
        cout << "   FAILED: " << message << endl;
        << "    Expected: " << expected << " Actual: " << actual << endl;
    }
}
