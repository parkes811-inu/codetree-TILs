#include <iostream>
#include <vector>
#include <algorithm> // max 함수를 사용하기 위해 포함

using namespace std;

int n;
vector<vector<int>> arr;
int dx[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
int dy[4] = {0, 0, -1, 1};
int maxTime = 0;

int simulate(int direction, int x, int y) {
    int time = 0;

    while (true) {
        time++;
        int nx = x + dx[direction];
        int ny = y + dy[direction];

        // 격자를 벗어나는 경우 루프 종료
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            break;
        }

        // 방향 전환 로직
        if (arr[nx][ny] == 1) {
            // 반사판 1에서의 방향 변경
            if (direction == 0) direction = 3;
            else if (direction == 1) direction = 2;
            else if (direction == 2) direction = 1;
            else if (direction == 3) direction = 0;
        } else if (arr[nx][ny] == 2) {
            // 반사판 2에서의 방향 변경
            if (direction == 0) direction = 1;
            else if (direction == 1) direction = 0;
            else if (direction == 2) direction = 3;
            else if (direction == 3) direction = 2;
        }

        // 다음 위치로 이동
        x = nx;
        y = ny;
    }

    return time;
}

int main() {
    cin >> n;
    arr.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int idx = 0; idx < n; idx++) {
        maxTime = max(maxTime, simulate(1, idx, -1)); // 상 -> 하
        maxTime = max(maxTime, simulate(3, idx, n)); // 하 -> 상
        maxTime = max(maxTime, simulate(2, -1, idx)); // 좌 -> 우
        maxTime = max(maxTime, simulate(0, n, idx)); // 우 -> 좌
    }

    cout << maxTime << endl;

    return 0;
}