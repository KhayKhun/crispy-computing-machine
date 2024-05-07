#include <iostream>
#include <ctime>
using namespace std;

int random(){
    return rand() % 9;
}

void draw(char *board){
    cout << "\n---------------\n";
    for(int i=0; i<7; i+=3){
        for(int j=0; j<3; j ++){
            cout << board[i+j] << ' ';
        }
        cout << endl;
    }
    cout << "\n---------------\n";}

bool isValid(int n, char *board){
    int x = n - 1;
    return x >= 0 && x <= 8 && board[x] == '_';
}

char checkWin(char board[])
{
    // Check rows
    for (int i = 0; i < 3; ++i) if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != '_') return board[i * 3]; // Return the winner
    // Check columns
    for (int i = 0; i < 3; ++i) if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != '_') return board[i]; // Return the winner
    // Check diagonals
    if ((board[0] == board[4] && board[4] == board[8] && board[0] != ' ') || (board[2] == board[4] && board[4] == board[6] && board[2] != '_')) return board[4]; // Return the winner
    // Check for draw
    for (int i = 0; i < 9; ++i) if (board[i] == '_') return 'N'; // Game not over yet

    return 'D'; // Game is a draw
}

int computerMoves(char board[]){
    int r = random();
    while(board[r] != '_'){
        r = random();
    }
    return r;
}

int main(){
    srand(time(NULL));

    char board[9];
    fill(board, board + 9, '_');

    int count = 0;
    bool running = true;
    
    draw(board);
    do{
        cout << "Insert a number from 1-9: " << endl;
        int n;
        cin >> n;
        if(isValid(n, board)){
            board[n-1] = 'X';
            draw(board);
            switch (checkWin(board))
            {
            case 'X':
                running = false;
                cout << "Player wins!" << endl;
                break;
            case 'O':
                running = false;
                cout << "Computer wins!" << endl;
                break;
            case 'D':
                running = false;
                cout << "Draw match!" << endl;
                break;
            case 'N':
                int pos = computerMoves(board);
                cout << "Computer chooses: " << pos + 1 << endl;
                board[pos] = 'O';
                draw(board);

                switch (checkWin(board)){
                case 'O':
                    running = false;
                    cout << "Computer wins!" << endl;
                    break;
                case 'D':
                    running = false;
                    cout << "Draw match!" << endl;
                    break;
                }
            }
        }else{
            cout << "Please enter a valid position." << endl;
        }

    }while(running);
    return 0;
}