#include <iostream>
#include <vector>
using namespace std;

const int N = 4;
vector<vector<int>> board(N, vector<int>(N));

// 타일을 왼쪽으로 이동시키는 함수
void moveLeft() {
    for (int i = 0; i < N; i++) {
        int last = -1, pos = 0;
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;
            if (last == -1 || board[i][j] != board[i][last]) {
                last = pos;
                board[i][pos++] = board[i][j];
            } else {
                board[i][last] *= 2;
                board[i][j] = 0;
                last = -1;
            }
        }
        for (int j = pos; j < N; j++) board[i][j] = 0;
    }
}

// 타일을 오른쪽으로 이동시키는 함수
void moveRight() {
    for (int i = 0; i < N; i++) {
        int last = N, pos = N - 1;
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] == 0) continue;
            if (last == N || board[i][j] != board[i][last]) {
                last = pos;
                board[i][pos--] = board[i][j];
            } else {
                board[i][last] *= 2;
                board[i][j] = 0;
                last = N;
            }
        }
        for (int j = pos; j >= 0; j--) board[i][j] = 0;
    }
}

// 타일을 위로 이동시키는 함수
void moveUp() {
    for (int j = 0; j < N; j++) {
        int last = -1, pos = 0;
        for (int i = 0; i < N; i++) {
            if (board[i][j] == 0) continue;
            if (last == -1 || board[i][j] != board[last][j]) {
                last = pos;
                board[pos++][j] = board[i][j];
            } else {
                board[last][j] *= 2;
                board[i][j] = 0;
                last = -1;
            }
        }
        for (int i = pos; i < N; i++) board[i][j] = 0;
    }
}

// 타일을 아래로 이동시키는 함수
void moveDown() {
    for (int j = 0; j < N; j++) {
        int last = N, pos = N - 1;
        for (int i = N - 1; i >= 0; i--) {
            if (board[i][j] == 0) continue;
            if (last == N || board[i][j] != board[last][j]) {
                last = pos;
                board[pos--][j] = board[i][j];
            } else {
                board[last][j] *= 2;
                board[i][j] = 0;
                last = N;
            }
        }
        for (int i = pos; i >= 0; i--) board[i][j] = 0;
    }
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    char d;
    cin >> d; // 방향 입력 ('L', 'R', 'U', 'D')

    switch (d) {
    case 'L':
        moveLeft();
        break;
    case 'R':
        moveRight();
        break;
    case 'U':
        moveUp();
        break;
    case 'D':
        moveDown();
        break;
    }

    printBoard(); // 결과 출력

    return 0;
}