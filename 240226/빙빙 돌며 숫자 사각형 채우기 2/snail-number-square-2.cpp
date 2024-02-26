#include <iostream>
using namespace std;

int n, m;
int x, y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dir;

int map[101][101];

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 1; i <= n * m; i++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(!(InRange(nx, ny)) || map[nx][ny] != 0) {
            dir = (dir + 1) % 4;
        }

        map[x][y] = i;
        x = x + dx[dir];
        y = y + dy[dir];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}