#include <iostream>
using namespace std;

int n, x, y;
char map[102][102];
// 방향: 우, 상, 좌, 하 (시계 방향으로 회전하며, 우측 벽을 따라갑니다)
int dx[4] = {0, -1, 0, 1}; 
int dy[4] = {1, 0, -1, 0};
// 시작 방향은 우측을 바라보는 것으로 설정
int dir = 0; 

// 위치가 격자 내부에 있는지 확인하는 함수
bool InRange(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

// 오른쪽에 벽이 있는지 검사하는 함수
bool HasWallToRight(int x, int y, int dir) {
    // 오른쪽 방향을 계산하기 위해 현재 방향에 대해 시계 방향으로 90도 회전
    int rightDir = (dir + 3) % 4; 
    int rightX = x + dx[rightDir];
    int rightY = y + dy[rightDir];

    // 오른쪽에 벽이 있다면 true를 반환
    return !InRange(rightX, rightY) || map[rightX][rightY] == '#';
}

int main() {
    cin >> n >> x >> y;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    int steps = 0;
    // while (true) {
    for(int i = 0; i < n * n; i++) {
        // 현재 위치에서 오른쪽에 벽이 있는지 검사
        if (!HasWallToRight(x, y, dir)) {
            // 오른쪽에 벽이 없다면 방향을 오른쪽으로 틀기
            dir = (dir + 3) % 4;
        }
        
        // 다음 위치 계산
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!InRange(nx, ny)) { // 격자 밖으로 나가면 탈출 성공
            cout << steps + 1 << endl;
            return 0;
        }
        
        if (map[nx][ny] == '.') {
            // 이동 가능하면 이동
            x = nx;
            y = ny;
            steps++;
        } else {
            // 벽에 막히면 방향 전환 (반시계 방향으로 90도 회전)
            dir = (dir + 1) % 4;
        }
    }
    cout << -1;
}