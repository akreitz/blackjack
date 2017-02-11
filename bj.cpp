#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
//#include "select.h"

using namespace std;

int selectCard();
string selectSuit();
void selectHand(int num, string suit);

int main() {
    srand(time(0));
    selectHand(selectCard(), selectSuit());
    return 0;
}

int selectCard() {
    int num = rand() % 13 + 1;
    return num;
}

string selectSuit() {
    string suit;
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    int r = rand() % 4;
    suit = suits[r];
    return suit;
}

void selectHand(int num, string suit) {
    int total(0);
    string x, y;
    string tens[4] = {"10", "J", "Q", "K"};

    for (int i = 0; i < 2; i++) {
        num = selectCard();
        suit = selectSuit();
        if ((num == 1) || (num > 10)) {
            switch (num) {
                case 1:
                    x = "A";
                    break;
                case 11:
                    x = "J";
                    break;
                case 12:
                    x = "Q";
                    break;
                case 13:
                    x = "K";
                    break;
            }
        }
        else {
        x = to_string(num);
        }
        if (num >= 10) {
            num = 10;
        }
        if ((num == 1)&&((num + total) <= 11)) {
            num = 11;
        }
        total += num;
        cout << x << " " << suit << endl;

    }
    cout << "total: " << total << endl;
    
}
