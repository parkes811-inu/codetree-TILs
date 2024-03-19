#include <iostream>
#include <vector>
using namespace std;

int n;
int map[102][102];

int dx[4] = {1, 0, -1, 0}; // 아래, 왼쪽, 위, 오른쪽 방향
int dy[4] = {0, -1, 0, 1};
int answer;

// 격자 내에서 구슬의 이동을 시뮬레이션하는 함수
int simulate(int x, int y, int dir) {
    int time = 1;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        time++;
        if (x < 0 || x >= n || y < 0 || y >= n) break; // 격자 밖으로 나가는 경우
        if (map[x][y] == 1) { // / 모양
            if (dir == 0) dir = 1;
            else if (dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else if (dir == 3) dir = 2;
        } else if (map[x][y] == 2) { // \ 모양
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else if (dir == 3) dir = 0;
        }
    }
    return time;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int maxTime = 0;
    // 4 * n 개의 가능한 시작점에 대해 시뮬레이션을 진행합니다.
    for (int i = 0; i < n; ++i) {
        maxTime = max(maxTime, simulate(0, i, 0)); // 위에서 아래로
        maxTime = max(maxTime, simulate(i, n - 1, 1)); // 오른쪽에서 왼쪽으로
        maxTime = max(maxTime, simulate(n - 1, i, 2)); // 아래에서 위로
        maxTime = max(maxTime, simulate(i, 0, 3)); // 왼쪽에서 오른쪽으로
    }

    cout << maxTime << endl;
    return 0;
}