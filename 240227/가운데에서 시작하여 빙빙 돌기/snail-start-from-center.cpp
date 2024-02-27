#include <iostream>

using namespace std;

int n;

int x, y;
int dir;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int map[101][101];

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    x = n / 2;
    y = n / 2;
    map[x][y] = 1;

    for(int i = 2; i <= n * n; i++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(!(InRange(nx, ny)) || map[nx][ny] != 0) {
            dir = (dir + 1) % 4;
        }
        x = x + dx[dir];
        y = y + dy[dir];
        map[x][y] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}