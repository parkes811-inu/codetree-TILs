#include <iostream>
#include <vector>
using namespace std;

int n;
int map[102][102];
int dx[] = {0, 1, 0, -1}; // 동, 남, 서, 북 방향
int dy[] = {1, 0, -1, 0};

// 격자 내에서 구슬의 이동을 시뮬레이션하는 함수
int simulate(int x, int y, int dir) {
    int time = 0;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        time++;
        if (x < 0 || x >= n || y < 0 || y >= n) return time; // 격자 밖으로 나가는 경우
        if (map[x][y] == 1) { // / 모양
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else if (dir == 3) dir = 0;
        } else if (map[x][y] == 2) { // \ 모양
            if (dir == 0) dir = 1;
            else if (dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else if (dir == 3) dir = 2;
        }
    }
    return time;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];
    
    int maxTime = 0;
    // 4 * n 개의 가능한 시작점에 대해 시뮬레이션을 진행합니다.
    for (int i = 0; i < n; ++i) {
        maxTime = max(maxTime, simulate(-1, i, 1)); // 상단에서 남쪽으로 진입
        maxTime = max(maxTime, simulate(n, i, 3)); // 하단에서 북쪽으로 진입
        maxTime = max(maxTime, simulate(i, -1, 0)); // 좌측에서 동쪽으로 진입
        maxTime = max(maxTime, simulate(i, n, 2)); // 우측에서 서쪽으로 진입
    }

    cout << maxTime << endl;
    return 0;
}