#include <iostream>

using namespace std;
int sum, n, t;
string cmd;
int map[101][101];
int x, y, dir;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    cin >> cmd;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    x = n / 2, y = n / 2;
    sum = sum + map[x][y];

    for(int i = 0; i < t; i++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];


        if(cmd[i] == 'R') {
            dir = (dir + 1) % 4;
        }
        else if(cmd[i] == 'L') {
            dir = (dir - 1 + 4) % 4;
        }

        else if(cmd[i] == 'F' && InRange(nx, ny)) {
            x = x + dx[dir];
            y = y + dy[dir];
           // cout << map[x][y] << ' ';
            sum = sum + map[x][y];
        }
    }
    cout << sum;
    return 0;
}