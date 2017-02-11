#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

std::string randomSuit() {
    int r(0);
    std::string suit;
    std::string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    r = rand() % 4;
    suit = suits[r];
    return suit;
}
