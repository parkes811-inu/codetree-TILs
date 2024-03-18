#include <iostream>
using namespace std;

int n, x, y;
char map[102][102];
// 방향: 우, 하, 좌, 상 (시계 방향으로 회전)
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0};
int dir = 0; // 초기 방향: 우측

bool InRange(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

// 오른쪽에 벽이 있는지 확인하는 함수
bool HasWallToRight(int x, int y, int dir) {
    // 현재 방향 기준으로 오른쪽 방향을 확인하기 위해 시계 방향으로 90도 회전
    int rightDir = (dir + 1) % 4;
    int rightX = x + dx[rightDir];
    int rightY = y + dy[rightDir];

    // 오른쪽에 벽이 있다면 true 반환
    return map[rightX][rightY] == '#';
}

int main() {
    cin >> n >> x >> y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    int steps = 1;
    for(int i = 0; i < n * n; i++) {
        // 오른쪽에 벽이 있는지 확인
        if (!HasWallToRight(x, y, dir)) {
            // 오른쪽에 벽이 없다면 시계 방향으로 90도 회전
            dir = (dir + 1) % 4;
        }

        // 다음 위치로 이동
        int nx = x + dx[dir], ny = y + dy[dir];

        if (!InRange(nx, ny)) { // 격자 밖으로 나가면 탈출 성공
            cout << steps << endl;
            break;
        }

        if (map[nx][ny] == '.') {
            // 이동할 수 있는 경우 앞으로 이동
            x = nx;
            y = ny;
            steps++;
        } else {
            // 벽을 만나면 반시계 방향으로 90도 회전
            dir = (dir + 3) % 4;
        }
    }

    return 0;
}