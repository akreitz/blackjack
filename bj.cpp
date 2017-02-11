#include <iostream>
#include <string>
#include "select.h"

using namespace std;

int main() {
    int card = randomCard();
    std::string suit = randomSuit();
    cout << card << " of " << suit << endl;
    return 0;
}
