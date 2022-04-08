#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// Main variables

static char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}, ch1;
int kolom, rij;
string speler1 = "", speler2 = "";
int loc = 0;

// This will reset the board

void resetBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// This will print the board

void printBoard()
{
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                cout << "\t\t\t";
            cout << " " << board[i][j] << " ";
            if (j != 2)
                cout << "|";
        }
        cout << "\n";
        if (i != 2)
            cout << "\t\t\t-----------\n";
    }
}

// This is where the game checks constantyl for a winner

bool isWinnaar(char char2)
{
    return ((board[0][0] == char2 && board[0][1] == char2 && board[0][2] == char2) ||
            (board[1][0] == char2 && board[1][1] == char2 && board[1][2] == char2) ||
            (board[2][0] == char2 && board[2][1] == char2 && board[2][2] == char2) ||
            (board[0][0] == char2 && board[1][0] == char2 && board[2][0] == char2) ||
            (board[0][1] == char2 && board[1][1] == char2 && board[2][1] == char2) ||
            (board[0][2] == char2 && board[1][2] == char2 && board[2][2] == char2) ||
            (board[0][0] == char2 && board[1][1] == char2 && board[2][2] == char2) ||
            (board[0][2] == char2 && board[1][1] == char2 && board[2][0] == char2));
}

// Check if the board is full

bool boardVol()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// This is the move function that will be called by the players

void positieVeranderen(char kolom1)
{
    if (board[rij - 1][kolom - 1] == ' ')
        board[rij - 1][kolom - 1] = kolom1;
    else
    {
        cout << "\nDeze plek is al bezet!\n\n";
        loc--;
    }
}

// The game starting function

void startSpel()
{
    do
    {
        if (loc % 2 == 0)
        {
            cout << endl
                 << "\n|| "
                 << speler1 << " is nu aan de beurt: ||\n\n";
            ch1 = 'X';
        }
        else
        {
            cout << endl
                 << "\n|| "
                 << speler2 << " is nu aan de beurt: ||\n\n";
            ch1 = 'O';
        }
        while (1)
        {
            cout << "Voer het Kolomnummer in: ";
            cin >> kolom;
            if (kolom < 1 || kolom > 3)
                cout << "Voer tussen de 1 en 3 als kolomnummer in\n";
            else
                break;
        }
        while (1)
        {
            cout << "Voer het rijnummer in: ";
            cin >> rij;
            if (rij < 1 || rij > 3)
                cout << "Voer tussen de 1 en 3 als rijnummer in\n";
            else
                break;
        }
        positieVeranderen(ch1);
        loc++;
        printBoard();
    } while (!isWinnaar(ch1) && !boardVol());
}

// he following is the code to name the first player

string player1Choice()
{

    for (;;)
    {
        cout << "\nNaam eerste speler: " << endl;
        getline(cin, speler1);

        if (speler1.empty())
        {
            cout << "Voer de naam van de eerste speler in aub!" << endl;
        }
        else
        {
            cout << "\n\nHet symbool (X) is succesvol toegewezen aan " << speler1 << "\n\n";
            return speler1;
        }
    }
}

// he following is the code to name the second player

string player2Choice()
{

    for (;;)
    {

        cout << "\nNaam tweede speler: " << endl;
        getline(cin, speler2);

        if (speler2.empty())
        {
            cout << "Voer de naam van de tweede speler in aub!" << endl;
        }
        else
        {
            cout << "\n\nHet symbool (X) is succesvol toegewezen aan " << speler2 << "\n\n";
            return speler2;
        }
    }
}

void loadingBar()
{
    cout << "\n\n\n";
    float progress = 0.0;
    while (progress < 1.0)
    {
        int barWidth = 70;

        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i)
        {
            if (i < pos)
                std::cout << "=";
            else if (i == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        std::cout.flush();

        progress += 0.16; // for demonstration only
    }
    std::cout << std::endl;
}

// This the welcome message

void welcomScherm()
{
    cout << "=====================================================================================================================" << endl;
    cout << "\t\t\t\tEA Sports, it's in the game! Ik bedoel welkom naar TicTacToe!\n\n\tGa je gang en voer de namen van de eerste en tweede spelers in voordat je het gaat beginnen spelen\n\n\t\t\t\t\t\t\tCopyright ©Yazan Al Akkad" << endl;
    cout << "=====================================================================================================================" << endl;

    loadingBar();

    Sleep(5000);
    system("cls");
}

// Main game code, this where everything gets executed and the game starts - Yazan

int main()
{
    char vraag;
    system("cls");

    do
    {
        resetBoard();
        welcomScherm();
        player1Choice();
        player2Choice();
        cout << "\n\nBedankt! Nu kunnen we het spel starten, veel plezier!\n"
             << endl;
        printBoard();
        startSpel();
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\tResultaat: ";
        if (boardVol() && !(isWinnaar('X') || isWinnaar('O')))
            cout << "Niemand heeft gewonnen!\n";
        else if (loc % 2 == 0)
            cout << speler2 << " heeft gewonnen!\n";
        else
            cout << speler1 << " heeft gewonnen!\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "\nWil je eens nog een keer spelen? (J / N): ";
        loc = 0;
        cin >> vraag;

    } while (vraag != 'n' && vraag != 'N');
}