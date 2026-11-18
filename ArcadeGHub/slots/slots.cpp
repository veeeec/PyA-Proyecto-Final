#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;


int main(){
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8);
    ifstream file("prize.txt");
    string prize[32];
    string line;
    bool playAgain = true;

    double bal;
    ifstream fileBalance("balance.txt");
    if (fileBalance.is_open())
    {
        fileBalance >> bal;
        fileBalance.close();
    }
    else
    {
        bal = 100.00;
    }

    double apuesta;
   
    do
    {
         cout << "You have: " << bal << endl;
    cout << "Enter your bet: " << endl;
    cin >> apuesta;
    while (apuesta <= 0 || apuesta > bal)
    {
        cout << "Invalid bet. Enter again." << endl;
        cin >> apuesta;
    }
    if (bal >= apuesta)
    {
        bal -= apuesta;
    }
    else
    {
        cout << "No credits." << endl;
    }
    
    

    int number;
    string emoji;


    while (getline(file, line))
{
        size_t separator = line.find('|');

        if (separator != string::npos)
        {
            number = stoi(line.substr(0, separator));
            emoji = line.substr(separator + 1);

            prize[number] = emoji;
        }
    }
    file.close();

    int slot1 = rand() % 32;
    int slot2 = rand() % 32;
    int slot3 = rand() % 32;
    cout << prize[slot1] << " " << prize[slot2] << " " << prize[slot3] << endl;

    if (slot1 == 7 && slot2 == 7 && slot3 == 7)
    {
        bal = bal + (apuesta*77.7);
    }
    else if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3)
    {
        bal = bal + (apuesta*1.5);
    }
    else if (slot1 == slot2 && slot2 == slot3)
    {
        bal = bal + (apuesta*11.1);
    }
    else if (slot1 == 31 || slot2 == 31 || slot3 == 31)
    {
        bal = bal + (apuesta*1.8);
    }
    else
    {
        bal;
    }

    ofstream output("balance.txt");
    output << bal;
    output.close();
    cout << "You now have: " << bal << " credits." << endl;
    cout << "Play again? "<< "1 YES / 0 NO" << endl;
    cin >> playAgain;
    } while (playAgain);
//MAIN MENU LOCATION
return 0;
}