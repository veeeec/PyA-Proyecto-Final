#include <iostream>
using namespace std;

int main(){
    int game;
    cout << "=== Arcade ===" << endl;
    cout << "=== Choose a game ===" << endl;
    cout << "1. Number guessing" << endl;
    cout << "2. Dice" << endl;
    cout << "3. Go fish" << endl;
    cout << "4. Roulette" << endl;
    cout << "5. Slots" << endl;
    cout << "6. Rock Paper Scissors" << endl;
    cout << "0. EXIT" << endl;
    cin >> game;

    switch(game)
    {
        case 0:
            cout << "You're no fun..." << endl;
            break;
        case 1:
            cout << "Number guessing it is..." << endl;
            system("C:\\higherlower.cpp\\numbergame.exe");
            break;
        case 2:
            cout << "Dice it is..." << endl;
            system("C:\\die.cpp\\die.exe");
            break;
        case 3:
            cout << "Blackjack!!!!!!!!" << endl;
            system("C:\\blackjack\\blackjack.exe");
            break;
        case 4:
            cout << "Roulette time!" << endl;
            system("roulette\\roulette.exe");
            break;
        case 5:
            cout << "Slots time!" << endl;
            system("slots\\slots.exe");
            break;
        case 6:
            cout << "Shoot!" << endl;
            system("rps\\rps.exe");
            break;
    }
    return 0;
}