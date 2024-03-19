#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, m, r, c;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int answer;

int map[102][102];

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

void makeBomb(int x, int y, int t) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * t;
        int ny = y + dy[i] * t;

        if (InRange(nx, ny) && map[nx][ny] == 0) {
            map[nx][ny] = 1;
        }
    }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //cout << map[i][j] << ' ';
            if (map[i][j] == 1) {
                answer++;
            }
        }
       // cout << '\n';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> r >> c;

    map[r][c] = 1;
    queue<pair<int, int>> list;
    for (int t = 1; t <= m; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] == 1) {
                    list.push({ i, j });
                }
            }
        }

        while(!list.empty()) {
            pair<int, int> cur = list.front();
            list.pop();
            map[cur.first][cur.second] = 1;
            makeBomb(cur.first, cur.second,  pow(2, t - 1));
        }
    }

    print();
    cout << answer;
    return 0;
}