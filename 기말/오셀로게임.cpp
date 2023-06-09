#include <iostream>
using namespace std;

void setBoard(char board[][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            board[i][j] = '+';
        }
    }
    board[3][3] = 'O';
    board[4][4] = 'O';
    board[3][4] = 'X';
    board[4][3] = 'X';
}

void checkBoard(char board[][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

void Xplace(char board[][8], int a, int b) {
    board[a][b] = 'X';
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    for (int i = 0; i < 8; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] != 'O') {
            continue;
        }
        bool isValid = false;
        int nnx = nx + dx[i];
        int nny = ny + dy[i];
        while (nnx >= 0 && nnx < 8 && nny >= 0 && nny < 8) {
            if (board[nnx][nny] == 'X') {
                isValid = true;
                break;
            }
            else if (board[nnx][nny] == '+') {
                break;
            }
            nnx += dx[i];
            nny += dy[i];
        }
        if (isValid) {
            int tx = nx;
            int ty = ny;
            while (tx != nnx || ty != nny) {
                board[tx][ty] = 'X';
                tx += dx[i];
                ty += dy[i];
            }
        }
    }
}
void Oplace(char board[][8], int a, int b) {
    board[a][b] = 'O';
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    for (int i = 0; i < 8; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] != 'X') {
            continue;
        }
        bool isValid = false;
        int nnx = nx + dx[i];
        int nny = ny + dy[i];
        while (nnx >= 0 && nnx < 8 && nny >= 0 && nny < 8) {
            if (board[nnx][nny] == 'O') {
                isValid = true;
                break;
            }
            else if (board[nnx][nny] == '+') {
                break;
            }
            nnx += dx[i];
            nny += dy[i];
        }
        if (isValid) {
            int tx = nx;
            int ty = ny;
            while (tx != nnx || ty != nny) {
                board[tx][ty] = 'O';
                tx += dx[i];
                ty += dy[i];
            }
        }
    }
}


void checkRock(char board[][8], int& Xcnt, int& Ocnt){
    Xcnt = 0;
    Ocnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[j][i] == 'X'){
                Xcnt++;
            }
            if(board[j][i] == 'O'){
                Ocnt++;
            }
        }
    }
}

int main(){
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        char board[8][8];
        setBoard(board);
        int cnt;
        cin >> cnt;
        if(cnt > 60){
            cnt = 60;
        }
        bool Xturn = true; bool Oturn = false;
        int Xcnt = 0;
        int Ocnt = 0;
        int a = 0; int b = 0;
        while(cnt > 0){
            if(Xturn){
                cin >> a >> b;
                Xplace(board, a-1, b-1);
                Xturn = false; Oturn = true;
                cnt--;
            }
            if(Oturn){
                cin >> a >> b;
                Oplace(board, a-1, b-1);
                Oturn = false; Xturn = true;
                cnt--;
            }
        }
        checkRock(board, Xcnt, Ocnt);
        cout << Xcnt << ' ' << Ocnt << endl;
        checkBoard(board);
    }
}
