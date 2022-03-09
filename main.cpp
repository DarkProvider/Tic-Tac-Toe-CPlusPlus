#include <iostream>
#include <iomanip>

using namespace std;

static char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}, ch1;;

int x, o;
string player1 = "", player2 = "";
int loc = o;

string player1Choice();
string player2Choice();



int resetBoard() {

}

string player1Choice(){

    for (;;){
        cout << "\nFirst player name: " << endl;
        getline(cin, player1);

        if (player1.empty()) {
            cout << "Please enter the first player's name" << endl;
        } else {
            player2Choice();
        }
    }

}

string player2Choice(){

    for (;;){

        cout << "\nSecond player name: " << endl;
        getline(cin, player2);

        if (player2.empty()) {
            cout << "Please enter the second player's name" << endl;
        } else {
            break;
        }

    }

}

void welcomeScreen() {

    cout << "=====================================================================================================================" << endl;
    cout << "Welcome to the C++ made Tic-Tac-Toe! \n\nPlease go ahead and enter the names of the first and second players before you start playing" << endl;
    cout << "=====================================================================================================================" << endl;
    player1Choice();


};



int printBoard() {

}

int isWinner() {

}

int makeMove() {

}

int boardFull() {

}

int startGame() {

}

int main() {

    resetBoard();
    welcomeScreen();

    cout << "\nThanks! Now we can start the game, have fun!" << endl;


    return 0;
}
