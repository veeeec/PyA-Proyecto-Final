#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
using namespace std;

char spinForColor(int winningNumber);
bool spinForNumber(int winningNumber, int chosenNumber);
float winOrLose(bool wol, char shade, char chosenShade, float balance, float bet, char betType);

int main(){
    srand(time(0));

    bool playAgain = true;

    int winningNumber = rand() % 37; //Which number landed on the wheel?
    int chosenNumber; //What number the player wants to bet on


    float balance;
    ifstream fileBalance("balance.txt");
    if (fileBalance.is_open())
    {
        fileBalance >> balance;
        fileBalance.close();
    }
    else
    {
        balance = 100.0;
    }

    float bet; //What is being bet
    char betType; // For menu use dont use elsewhere

    char shade; //Which color landed on the wheel?
    char chosenShade; //Which color the player wants to bet on
    bool wol; //Win (true) or lose(0)

    do
    {
        if (balance <= 0)
    {
        cout << "You're broke you can't gamble." << endl;
        exit(0);
    }
    

    cout << "You have " << balance << " points." << endl;
    cout << "What will you bet on? "<< endl;
    cout << "[C] Color (Pays 1:1 and 35:1 for green) || [N] Number (Pays 35:1) "<< endl;
    cin >> betType;
    betType = toupper(betType);

    switch (betType)
    {
    case 'C': // Spins for color
        cout << "Choose a color to bet on. [R] Red || [B] Black || [G] Green" << endl;
        cin >> chosenShade;
        chosenShade = toupper(chosenShade);
        cout << "Choose how much credits to bet." << endl;
        cin >> bet;
        if (bet <= 0)
        {
            cout << "Invalid bet." << endl;
            exit(0);
        }
        
        
        shade = spinForColor(winningNumber);
        balance = winOrLose(wol, shade, chosenShade, balance, bet, betType);
        cout << "Roulette landed on " << winningNumber << ". Your current balance is: " << balance << endl;
        break;

    case 'N':
        cout << "Choose a number to bet on. (0-36)" << endl;
        cin >> chosenNumber;
        cout << "Choose how much credits to bet." << endl;
        cin >> bet;
        if (bet <= 0)
        {
            cout << "Invalid bet." << endl;
            exit(0);
        }
        wol = spinForNumber(winningNumber, chosenNumber);
        balance =  winOrLose(wol, shade, chosenShade, balance, bet, betType);
        cout << "Roulette landed on " << winningNumber << ". Your current balance is: " << balance << endl;
        break;

    default:
        break;
    }

    ofstream output("balance.txt");
    output << balance;
    output.close();

    cout << "Wanna play again?   1 FOR YES / 0 FOR NO" << endl;
    cin >> playAgain;
    } while (playAgain);
    system("C:\\Users\\ferni\\Documents\\arcade\\arcade.exe");
    
    return 0;
}

// Prototype functions
char spinForColor(int winningNumber){
    char shade; 
    if (winningNumber == 0)
    {
        shade = 'G';
        cout << "Roulette lands on GREEN!" << endl;
    }
    else if (winningNumber <= 18)
    {
        shade = 'R';
        cout << "Roulette lands on RED!" << endl;
    }
    else if (winningNumber > 18)
    {
        shade = 'B';
        cout << "Roulette lands on BLACK!" << endl;
    }
    return shade;
}

bool spinForNumber(int winningNumber, int chosenNumber){
    bool wol;
    if (winningNumber == chosenNumber)
    {
        wol = true;
    }
    else
    {
        wol = false;
    }
    return wol;
}

float winOrLose(bool wol, char shade, char chosenShade, float balance, float bet, char betType){
    if (betType == 'C')
    {
        if (shade == chosenShade)
        {
            balance = (balance - bet) + (bet*2.0);
        }
        else
        {
            balance = (balance - bet);
        }
    }
    else 
    {
        if (wol == true)
        {
            balance = (balance - bet) + (bet*35.0);
        }
        else
        {
            balance = (balance - bet);
        }
    }
    return balance;
}