#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void menuGame(char optoin);
void guessChecker(int &guess);

int main(){
    srand(time(0));
    bool playAgain = true;
    int guess;
    int attempts = 1;
    do
    {
        int winningNumber = (rand() % 99) + 1;
        cout << "Number is from 0 to 100" << endl;

        while (guess != winningNumber)
        {
            cout << "Make your guess: ";
        cin >> guess;
        guessChecker(guess);

        attempts++;

        if (guess == winningNumber)
        {
            cout << "You win in " << attempts << " attempts!" << endl;
        }
        else if (guess < winningNumber)
        {
           cout << "Pick a bigger number." << endl;
        }
        else if (winningNumber < guess)
        {
            cout << "Pick a smaller number." << endl;
        }
        
        }
        
        

        cout << "Wanna play again?   1 FOR YES / 0 FOR NO" << endl;
        cin >> playAgain;
    } while (playAgain);
    exit(0);
//MAIN MENU LOCATION
}

void guessChecker(int &guess){
    if (guess < 0 || guess > 100 )
    {
        cout << "Invalid guess. Try again." << endl;
        cin >> guess;
    }
    
}