#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);

    cin >> n >> t;
    cin >> r >> c >> d;

    int x = r;
    int y = c;
    int dir = 0;

    if(d == 'U') {
        dir = 0;
    }
    else if(d == 'D') {
        dir = 3;
    }
    else if(d == 'R') {
        dir = 2;
    }
    else if(d == 'L') {
        dir = 1;
    }

    for (int i = 0; i < t; i++) {

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx > n || ny > n || nx < 1 || ny < 1) {
            dir = (dir + 1) % 4;
            continue;
        }
        x = x + dx[dir];
        y = y + dy[dir];
    }
    cout << x << ' ' << y;
    return 0;
}