
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int generateCard();
int cardValue(int card);
int calculateSum(int cards[], int amount);
void showCard(int card);

int main(){
    srand(time(0));

    int playAgain = 1;

    float balance;
    ifstream fileBalance("balance.txt");

    if (fileBalance.is_open()){
        if (!(fileBalance >> balance)){
            balance = 100.0;
        }
        fileBalance.close();
    }
    else {
        balance = 100.0;
    }

    do {

        // RESET VARIABLES EVERY ROUND
        int player[5];
        int computer[5];

        int playerCards = 2;
        int computerCards = 2;

        int playerSum, computerSum;
        int choice;
        int bet;

        // CHECK BALANCE
        if (balance < 1){
            cout << "YOU ARE BROKE" << endl;
            break;
        }

        cout << "=== BLACKJACK ===" << endl;
        cout << "You have: " << balance <<"credits" << endl;

        // PLACE BET
        do {
            cout << "Enter your bet: ";
            cin >> bet;

            if (bet < 1 || bet > balance){
                cout << "Invalid bet! Enter an amount between 1 and "
                     << balance << endl;
            }

        } while (bet < 1 || bet > balance);

        // GENERATE CARDS
        for (int i = 0; i < 5; i++){
            player[i] = generateCard();
            computer[i] = generateCard();
        }

        // PLAYER'S INITIAL HAND
        cout << "\nYour cards: ";

        for (int i = 0; i < playerCards; i++){
            showCard(player[i]);
        }

        playerSum = calculateSum(player, playerCards);

        cout << "\nYour total: " << playerSum << endl;

        // PLAYER'S TURN
        while (playerSum < 21 && playerCards < 5){

            cout << "\n1. Hit";
            cout << "\n2. Stand";
            cout << "\nChoose: ";
            cin >> choice;

            if (choice == 1){

                cout << "\nNew card: ";
                showCard(player[playerCards]);

                playerCards++;

                playerSum = calculateSum(player, playerCards);

                cout << "\nYour total: " << playerSum << endl;

            }
            else if (choice == 2){
                break;
            }
            else {
                cout << "\nInvalid choice!" << endl;
            }
        }

        // CHECK IF PLAYER BUSTED
        if (playerSum > 21){
            cout << "\nYou busted! Computer wins." << endl;
        }

        else {

            // COMPUTER'S TURN
            cout << "\n=== COMPUTER'S TURN ===" << endl;

            cout << "\nComputer cards: ";

            for (int i = 0; i < computerCards; i++){
                showCard(computer[i]);
            }

            computerSum = calculateSum(computer, computerCards);

            cout << "\nComputer total: " << computerSum << endl;

            while (computerSum < 17 && computerCards < 5){

                cout << "\nComputer draws: ";
                showCard(computer[computerCards]);

                computerCards++;

                computerSum = calculateSum(computer, computerCards);

                cout << "\nComputer total: " << computerSum << endl;
            }
        }

        // DETERMINE WINNER AND UPDATE BALANCE

        cout << "Player: " << playerSum << endl;

        if (playerSum <= 21){
            cout << "Computer: " << computerSum << endl;
        }

        if (playerSum > 21){
            cout << "You went over 21"<< endl;
            balance -= bet;
        }
        else if (computerSum > 21){
            cout << "Dealer bust."<< endl;
            balance += bet;
        }
        else if (playerSum > computerSum){
            cout << "You win!"<< endl;
            balance += bet;
        }
        else if (computerSum > playerSum){
            cout << "Computer wins!"<< endl;
            balance -= bet;
        }
        else {
            cout << "Tie!" << endl;
        }

        // DISPLAY UPDATED BALANCE
        cout << "You have: " << balance << " credits" << endl;

        // SAVE BALANCE
        ofstream output("balance.txt");

        if (output.is_open()){
            output << balance;
            output.close();
        }
        else {
            cout << "Error saving balance!" << endl;
        }

        // PLAY AGAIN
        if (balance < 1){
            cout << "You have run out of credits!" << endl;
            break;
        }

        cout << "Play again? (1 YES / 0 NO): " << endl;
        cin >> playAgain;

        while (playAgain != 1 && playAgain != 0){
            cout << "Invalid ";
            cin >> playAgain;
        }

    } while (playAgain == 1);

//MAIN MENU LOCATION

    return 0;
}


// GENERATE RANDOM CARD
int generateCard(){
    return rand() % 13 + 1;
}


// CONVERT CARD TO BLACKJACK VALUE
int cardValue(int card){
    if (card == 1){
        return 11;
    }
    else if (card >= 11){
        return 10;
    }
    else {
        return card;
    }
}


// CALCULATE TOTAL INCLUDING ACES
int calculateSum(int cards[], int amount){
    int sum = 0;
    int aces = 0;

    for (int i = 0; i < amount; i++){
        sum += cardValue(cards[i]);

        if (cards[i] == 1){
            aces++;
        }
    }

    while (sum > 21 && aces > 0){
        sum -= 10;
        aces--;
    }

    return sum;
}


// DISPLAY CARD
void showCard(int card){
    if (card == 1){
        cout << "Ace ";
    }
    else if (card == 11){
        cout << "Jack ";
    }
    else if (card == 12){
        cout << "Queen ";
    }
    else if (card == 13){
        cout << "King ";
    }
    else {
        cout << card << " ";
    }
}
