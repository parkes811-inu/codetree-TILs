#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 4;
vector<vector<int>> board(N, vector<int>(N));

void moveTiles(vector<int>& line) {
    vector<int> newLine;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != 0) {
            newLine.push_back(line[i]);
        }
    }

    for (int i = 0; i < newLine.size() - 1; i++) {
        if (newLine[i] == newLine[i + 1]) {
            newLine[i] *= 2;
            newLine[i + 1] = 0;
        }
    }

    line.clear();
    for (int i = 0; i < newLine.size(); i++) {
        if (newLine[i] != 0) {
            line.push_back(newLine[i]);
        }
    }

    while (line.size() < N) {
        line.push_back(0);
    }
}

void rotateBoard() {
    vector<vector<int>> temp(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            temp[j][N - 1 - i] = board[i][j];
        }
    }
    board = temp;
}

void moveLeft() {
    for (int i = 0; i < N; i++) {
        moveTiles(board[i]);
    }
}

void moveRight() {
    for (int i = 0; i < N; i++) {
        reverse(board[i].begin(), board[i].end());
        moveTiles(board[i]);
        reverse(board[i].begin(), board[i].end());
    }
}

void moveUp() {
    rotateBoard(); // Rotate clockwise
    moveLeft();
    rotateBoard(); // 3 times to get original orientation
    rotateBoard();
    rotateBoard();
}

void moveDown() {
    rotateBoard(); // Rotate clockwise 3 times
    rotateBoard();
    rotateBoard();
    moveLeft();
    rotateBoard(); // Once to get original orientation
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

    char dir;
    cin >> dir; // 방향 입력 ('L', 'R', 'U', 'D')

    switch (dir) {
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

    printBoard(); // 최종 결과 출력

    return 0;
}