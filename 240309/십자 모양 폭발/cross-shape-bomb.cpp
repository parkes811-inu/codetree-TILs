#include <iostream>

using namespace std;

int n;
int x, y;
int map[202][202];
int temp[202][202];

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x <= n && y <= n);
}

// remove
void removeBomb(int x, int y) {
    int cnt = map[x][y];
    if(cnt == 1) {
        map[x][y] = 0;
        return;
    }
    map[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int j = 0; j < cnt; j++) {
            int nx = x + (dx[i] * j);
            int ny = y + (dy[i] * j);
            if(InRange(nx, ny)) {
                map[nx][ny] = 0;
            }
        }
    }
}

// bomb
void bomb() {
    int last_tempIdx = n;

    for(int i = n; i > 0; i--) {
        for(int j = n; j > 0; j--) {
            if(map[j][i] > 0) {
                temp[last_tempIdx--][i] = map[j][i];
                map[j][i] = 0;
            }
        }
        last_tempIdx = n;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(temp[i][j] > 0) {
                map[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    cin >> x >> y;

    removeBomb(x, y);
    bomb();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}