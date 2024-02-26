#include <iostream>

using namespace std;

int n, t, r, c;
char d;
// r, d, u, l
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int dir;

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    cin >> r >> c >> d;
    r--, c--;
    if(d == 'U') {
        dir = 2;
    }
    else if(d == 'D') {
        dir = 1;
    }
    else if(d == 'R') {
        dir = 0;
    }
    else if(d == 'L') {
        dir = 3;
    }

    for(int i = 0; i < t; i++) {
        int nx = r + dx[dir], ny = c + dy[dir];
        if(InRange(nx, ny)) {
            r = nx, c = ny;
        }
        else {
            dir = 3 - dir;
        }
    }
    
    cout << r + 1 << ' ' << c + 1;
    return 0;
}