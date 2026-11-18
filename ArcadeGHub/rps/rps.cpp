#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int menu(){ // Instrucciones. Ponemos esta cosa aqui para que intmain se vea bonito, hermoso y limpio.
    int j;
    cout << "--- Rock Paper Scissors ---" << endl;
    cout << "[1] Rock" << endl;
    cout << "[2] Paper" << endl;
    cout << "[3] Scissors" << endl;
    cout << "--- Go ahead and choose... ---" << endl;
    cin >> j;
    while (j < 1 || j > 3)
    {
        cout << "Error. Don't break my game!" << endl;
    }
    
    return j;
}

int GRPS(int j){
    int c = rand()%3 + 1;
    cout << "Computer chose " << c << endl;

    if(j == c)
    {
        cout << "It's a tie..." << endl;
        return 2;
    }
    else if ((j == 1 && c == 3)||(j == 2 && c == 1 )||(j == 3 && c == 2)) // || Significa OR
    {
        cout << "Congratulations! You win!" << endl;
        return 1;
    }
    else
    {
        cout << "I win! Better luck next time!" << endl;
        return 0;
    }
}



int main(){
    srand(time(0));
    bool playAgain = true;
    
    do
    {
        int j = menu();
        int result = GRPS(j);
        cout << "Wanna play again?   1 FOR YES / 0 FOR NO" << endl;
        cin >> playAgain;
    } while (playAgain); 

//MAIN MENU LOCATION

    return 0;
}