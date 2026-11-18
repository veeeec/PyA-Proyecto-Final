#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void ruleBook();
void betCheck(int &bet, float balance);
void dnCheck(int &diceNumber);

int main(){
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    int dice1 = rand() % (6) +1;
    int dice2 = rand() % (6) +1;
    int dice3 = rand() % (6) +1;

    bool playAgain = true;

    char betType;
    char diceOptions;

    int bet;
    int diceNumber;
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
    
    do
    {
        cout << "Welcome to the dice game." << endl;
    cout << "[1] Play" << endl;
    cout << "[2] Rules" << endl;
    cout << "[3] Exit" << endl;
    cin >> diceOptions;
    switch (diceOptions)
    {
    case '1': //Player chooses to play

     if (balance <= 0)
        {
            cout << "You are broke and you can't play." << endl;
            exit(0);
        }

        cout << "Enter bet type." << endl;
        cout << "Single die bets: [1] One die match || [2] Two dice match || [3] Match" << endl;
        cout << "Any triple [4] || [5] Big bet || [6] Small bet" << endl;

        

        cin >> betType;
        betType = toupper(betType);

        switch (betType)
        {
        case '1': //one die match
            cout << "You have " << balance << " credits." << endl;
            cout << "Which number will the die land on? ";
            cin >> diceNumber;
            dnCheck(diceNumber);
            cout << "How many credits will you bet?" << endl;
            cin >> bet;
            betCheck(bet, balance);
            if (diceNumber == dice1 || diceNumber == dice2 || diceNumber == dice3)
            {
                balance = (balance - bet) + (bet*2);
            }
            else {
                balance = balance - bet;
            }
            break;
        
        case '2': //two dice match
            cout << "You have " << balance << " credits." << endl;
            cout << "Which number will the dice land on? ";
            cin >> diceNumber;
            dnCheck(diceNumber);
            cout << "How many credits will you bet?" << endl;
            cin >> bet;
            betCheck(bet, balance);
            if ((diceNumber == dice1) && (diceNumber == dice2) || (diceNumber == dice2) && (diceNumber == dice3) || (diceNumber == dice1) && (diceNumber == dice3))
            {
                balance = (balance - bet) + (bet*3);
            }
            else {
                balance = balance - bet;
            }
            break;

        case '3': //three dice match
            cout << "You have " << balance << " credits." << endl;
            cout << "Which number will the dice land on? ";
            cin >> diceNumber;
            dnCheck(diceNumber);
            cout << "How many credits will you bet?" << endl;
            cin >> bet;
            betCheck(bet, balance);
            if (diceNumber == dice1 && diceNumber == dice2 && diceNumber == dice3)
            {
                balance = (balance - bet) + (bet*11);
            }
            else {
                balance = balance - bet;
            }
            break;

        case '4':
            cout << "You have " << balance << " credits." << endl;
            cout << "How many credits will you bet?" << endl;
            cin >> bet;
            betCheck(bet, balance);
            if (dice1 == dice2 && dice2 == dice3)
            {
                balance = (balance - bet) + (bet*31);
            }
            else {
                balance = balance - bet;
            }
            break;
        
        case '5':
            cout << "How many credits will you bet?" << endl;
            cin >> bet;
            betCheck(bet, balance);
            if ((dice1 + dice2 + dice3) >= 12)
            {
                balance = (balance - bet) + (bet*2);
            }
            else {
                balance = balance - bet;
            }
            break;
/* Codigo hecho por Victor y una cantidad aceptable de GPT.
Proyecto final programacion y algoritmos

Cuando escuché al astrónomo erudito,
Cuando las pruebas, las cifras, fueron puestas en columnas delante de mí.
Cuando me enseñaron los mapas y los diagramas, para sumarlos, dividirlos, medirlos,
Cuando sentado escuché al astrónomo, con gran aplauso en el salón,
Qué extrañamente rápido me harté,
Hasta que levantándome y deslizándome me alejé solo,
En el aire nocturno, místico y húmedo, y de tiempo en tiempo,
Miré en perfecto silencio las estrellas.
- W.W.

*/
        case '6':
            cout << "How many credits will you bet?" << endl;
            cin >> bet;
            betCheck(bet, balance);
            if ((dice1 + dice2 + dice3) <= 11)
            {
                balance = (balance - bet) + (bet*2);
            }
            else {
                balance = balance - bet;
            }
            break;
            
        default:
            break;
        }
        cout << "Dice landed on: " << dice1 << ", " << dice2 << ", " << dice3 << endl;
        cout << "You have " << balance << " credits." << endl;
        break;

        


    case '2':
        ruleBook();
        break;
    
    case '3':
        exit(0);
        break;

    default:
        break;
    }


    ofstream output("balance.txt");
    output << balance;
    output.close();

    cout << "Play again? "<< "1 YES / 0 NO" << endl;
    cin >> playAgain;
    } while (playAgain);
    
  //MAIN MENU LOCATION
    

    return 0;
}

void ruleBook(){
    cout << "Three dice will be rolled. Bet on the numbers that will face up." << endl;
    cout << "===TYPES OF BETS===" << endl;
    cout << "Single Die Bet:" << endl;
    cout << "A specific number will appear: 1 die matches 1:1 -- 2 dice match 2:1 -- 3 dice match 10:1" << endl;
    cout << " " << endl;
    cout << "Any Triple:" << endl;
    cout << "Bet that all dice show the same number. Pays 30:1" << endl;
    cout << " " << endl;
    cout << "Big Bet:" << endl;
    cout << "The sum of all dice is 12 or higher. Pays 1:1" << endl;
    cout << " " << endl;
    cout << "Small Bet:" << endl;
    cout << "The sum of all dice is 11 or lower. Pays 1:1" << endl;
}

void betCheck(int &bet, float balance){
    while (bet <= 0 || bet > balance)
    {
        cout << "Invalid bet. Try again." << endl;
        cin >> bet;
    }
}

void dnCheck(int &diceNumber){
    while (diceNumber < 1 || diceNumber > 6)
{
    cout << "Invalid number. Choose between 1 and 6: ";
    cin >> diceNumber;
}
}