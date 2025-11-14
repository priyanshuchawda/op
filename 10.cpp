//Write a C++ program to implement the game Tic Tac Toe. 
//Apply the concept of polymorphism.

#include <iostream>
using namespace std;

// ---- Base Class (Polymorphism Source) ----
class Game {
public:
    virtual void play() = 0;   // pure virtual (abstract)
};

// ---- Derived Class Implementing Tic Tac Toe ----
class TicTacToe : public Game {
    char board[3][3];
    char player;

public:
    TicTacToe() {
        player = 'X';
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                board[i][j] = ' ';
    }

    void display() {
        cout << "\n";
        for(int i=0;i<3;i++) {
            cout << " ";
            for(int j=0;j<3;j++) {
                cout << board[i][j];
                if(j < 2) cout << " | ";
            }
            if(i < 2) cout << "\n-----------\n";
        }
        cout << "\n";
    }

    bool win() {
        for(int i=0;i<3;i++)
            if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
                return true;

        for(int i=0;i<3;i++)
            if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
                return true;

        if(board[0][0]==player && board[1][1]==player && board[2][2]==player) return true;
        if(board[0][2]==player && board[1][1]==player && board[2][0]==player) return true;

        return false;
    }

    // ---- Polymorphic Function ----
    void play() override {
        int moves = 0;

        while(moves < 9) {
            display();
            int r, c;
            cout << "\nPlayer " << player << " enter row & column (0-2): ";
            cin >> r >> c;

            if(r<0 || r>2 || c<0 || c>2 || board[r][c] != ' ') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[r][c] = player;
            moves++;

            if(win()) {
                display();
                cout << "\nPlayer " << player << " wins!\n";
                return;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        display();
        cout << "\nIt's a Draw!\n";
    }
};

int main() {
    TicTacToe t;
t.play();
       // polymorphic call

    return 0;
}
