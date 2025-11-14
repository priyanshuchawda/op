//Write a C++ program to implement the game Tic Tac Toe. 
//Apply the concept of polymorphism.

#include <iostream>
using namespace std;

class Game{
public:
    virtual void play() = 0;
};

class Tic: public Game{
    char board[3][3];
    char player;

public:
    Tic(){
        player = 'X';
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                board[i][j]= ' ';
            }
        }
    }

    void display(){
        cout<<endl;
        for(int i = 0 ; i < 3 ; i++){
            cout<<" ";
            for(int j = 0 ; j < 3 ; j++){
                cout<<board[i][j];
                if(j<2) cout<<" | ";
            }
            if(i<2) cout<<"\n----------------\n";
        }
        cout<<endl;
    }

    bool win(){
        for(int i = 0 ; i < 3 ; i++){
            if(board[i][0]== player && board[i][1]==player && board[i][2]==player) return true;
            if(board[0][i]== player && board[1][i]==player && board[2][i]==player) return true;
            if(board[0][0]== player && board[1][1]==player && board[2][2]==player) return true;
            if(board[0][2]== player && board[1][1]==player && board[2][0]==player) return true;
        }

        return false;
    }

    void play() override{
        int moves = 0 ; 
        while (moves<9){
            display();
            int r, c;

            cout<<"Enter row and column ";
            cin>>r;
            cin>>c;
            cout<<endl;

            if(r<0 || r>2 || c<0 || c>2){
                cout<<"invalid coordinates"<<endl;
                continue;
            }
            board[r][c]=player;
            moves++;

            if(win()){
                cout<<"player "<<player<<" won the game"<<endl;
                return ;
            }

            if (player == 'X') {
    player = 'O';
} else {
    player = 'X';
}

        }
        display();


    }
};

int main(){
    Game* g;
    Tic t;
    g=&t;
    g->play();
    return 0;
}