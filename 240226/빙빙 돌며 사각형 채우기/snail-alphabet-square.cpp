#include <iostream>
using namespace std;

int n, m;
char alpha = 'A';

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int map[101][101];
int dir;
int x, y;

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int main() {
    cin >> n >> m;
    // 여기에 코드를 작성해주세요.
    for(int i = 1; i <= n * m; i++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(!(InRange(nx, ny)) || map[nx][ny] != 0) {
            dir = (dir + 1) % 4;
        }

        map[x][y] = alpha++;
        x = x + dx[dir];
        y = y + dy[dir];
        if(alpha == 'Z') {
            alpha = 'A';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (char) map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}