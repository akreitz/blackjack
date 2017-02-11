#include <iostream>
#include <cstdlib>
#include <string>
#include "select.h"

using namespace std;

int selectCard() {
    random = rand() % 13 + 1;
    return random;
}

string selectSuit() {
    int r(0);
    string suit;
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    r = rand() % 4;
    suit = suits[r];
    return suit;
}
