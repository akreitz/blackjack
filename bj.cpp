// bj.cpp
// Author: Alex Kreitz
// Created: 2-10-17
// simple blackjack game

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int selectCard();
int oneCard(int num);
int twoCards(int num);
string tS(int num);
bool bustCheck(int hand);

int main() {
    srand(time(0));
    int card1(0), card2(0), pHand(0);
    char response1, response2;
    cout << "Would you like to play blackjack? y/n" << endl;
    cin >> response1;
    while ((response1 == 'y') || (response1 == 'Y')) {
        card1 = selectCard();
        card2 = selectCard();
        pHand = oneCard(card1) + oneCard(card2); // calculates value of hand
        if (bustCheck(pHand)) {
            card1 = 1;
            card2 = 1;
        }
        cout << tS(card1) << " " << tS(card2) << endl;
        cout << pHand << endl;
        if (pHand == 21) {
            cout << "Blackjack!" << endl;
        }
        do { // runs while player is legally able to still hit
            cout << "(h)it or (s)tay" << endl;
            cin >> response2;
            if ((response2 == 'h') || (response2 == 'H')) {
                int card3 = selectCard();
                cout << tS(card3) << endl;
                card3 = oneCard(card3);
                if ((card3 == 11)&&((card3 + pHand) > 21)) {
                    card3 = 1;
                    pHand += card3;
                }
                else if (((card1 == 1) || (card2 == 1))&&((card3 + pHand) > 21)) { // causing problems w/ A in hand
                    pHand += (card3 - 10);
                }
                else {
                    pHand += card3;
                }
                cout << pHand << endl;
            }
            
        } while ((!bustCheck(pHand))&&((response2 == 'h') || (response2 == 'H')));
        cout << pHand << endl;
        if (bustCheck(pHand)) {
            cout << "Busted!" << endl;
        }
        cout << "Would you like to play again? y/n" << endl;
        cin >> response1;
    }
    return 0;
}

int selectCard() {
    int num = rand() % 13 + 1;
    return num;
}

int oneCard(int num) {
    int total(0);
    if (num >= 10) {
        total = 10;
    }
    else if (num == 1) {
        total = 11;
    }
    else {
        total = num;
    }
    return total;
}

int twoCards(int num) {
    int total(0);
    for (int i = 0; i < 2; i++) {
        oneCard(num);        
        total += num;
    }
    return total;
}

string tS(int num) {
    string card;
    if ((num == 1) || (num > 10)) {
        switch (num) {
            case 1:
                card = "A";
                break;
            case 11:
                card = "J";
                break;
            case 12:
                card = "Q";
                break;
            case 13:
                card = "K";
                break;
        }
    }
    else {
        card = to_string(num);
    }
    return card;
}

bool bustCheck(int hand) {
    if (hand > 21) {
        return true;
    }
    else {
        return false;
    }
}

