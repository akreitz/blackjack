#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string randomSuit() {
    int r(0);
    string suit;
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    r = rand() % 4;
    suit = suits[r];
    return suit;
}
