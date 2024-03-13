#include <iostream>
#include <vector>
using namespace std;

const int N = 4;
vector<vector<int>> board(N, vector<int>(N));

void rotateBoard(char d) {
    vector<vector<int>> temp(N, vector<int>(N));
    if (d == 'R') { // 오른쪽으로 이동하는 경우 180도 회전
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[i][j] = board[N - 1 - i][N - 1 - j];
            }
        }
    } else if (d == 'U') { // 위로 이동하는 경우 270도 회전
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[j][N - 1 - i] = board[i][j];
            }
        }
    } else if (d == 'D') { // 아래로 이동하는 경우 90도 회전
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[N - 1 - j][i] = board[i][j];
            }
        }
    }
    if (d != 'L') { // 회전된 보드를 다시 board에 복사
        board = temp;
    }
}

void compressAndMerge() {
    for (int i = 0; i < N; i++) {
        vector<int> line;
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                line.push_back(board[i][j]);
            }
        }
        for (int j = 0; j < line.size() - 1; j++) {
            if (line[j] == line[j + 1]) {
                line[j] *= 2;
                line[j + 1] = 0;
            }
        }
        vector<int> newLine;
        for (int j = 0; j < line.size(); j++) {
            if (line[j] != 0) {
                newLine.push_back(line[j]);
            }
        }
        newLine.resize(N, 0);
        board[i] = newLine;
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

    rotateBoard(d); // 입력된 방향에 따라 보드 회전
    compressAndMerge(); // 숫자들을 압축하고 합침
    if (d == 'R' || d == 'U' || d == 'D') { // 회전된 보드를 원래대로 복귀
        rotateBoard('D'); rotateBoard('D');
        if (d == 'U') rotateBoard('D');
        if (d == 'D') rotateBoard('U');
    }
    printBoard(); // 결과 출력

    return 0;
}