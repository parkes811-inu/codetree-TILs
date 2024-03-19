#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;
int dx[4] = {0, 1, 0, -1}; // 오른쪽, 아래, 왼쪽, 위
int dy[4] = {1, 0, -1, 0};
// 반사판에서의 방향 변경
// reflectDir[반사판 타입][현재 방향] = 새로운 방향
int reflectDir[3][4] = {
    {0, 0, 0, 0}, // 0: 빈 공간, 방향 변경 없음
    {3, 2, 1, 0}, // 1: / 모양 반사판
    {1, 0, 3, 2}  // 2: \ 모양 반사판
};

bool inRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int simulate(int x, int y, int dir) {
    int cnt = 0;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        cnt++;
        if (!inRange(x, y)) break; // 격자 밖으로 나가면 종료
        if (board[x][y] != 0) { // 반사판을 만나면 방향 변경
            dir = reflectDir[board[x][y]][dir];
        }
    }
    return cnt;
}

int main() {
    cin >> n;
    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    int maxTime = 0;
    // 모든 가능한 시작점에서 시뮬레이션
    for (int i = 0; i < 4 * n; ++i) {
        int x = i < n ? 0 : i < 2 * n ? i - n : n - 1; // x 좌표 결정
        int y = i < n ? i : i < 2 * n ? n - 1 : 3 * n - i - 1; // y 좌표 결정
        int dir = i < n ? 1 : i < 2 * n ? 2 : 3; // 방향 결정
        maxTime = max(maxTime, simulate(x, y, dir));
    }

    cout << maxTime + 1 << endl;
    return 0;
}