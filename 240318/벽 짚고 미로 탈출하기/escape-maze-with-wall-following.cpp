#include <iostream>

using namespace std;
int n, x, y;
// n * n 격자에서 
// 우측 방향을 바라보고 시작하여
// 오른쪽 벽을 짚고 쭉 따라가는 방식으로 미로를 탈출하는 프로그램
// 규칙에 맞게 이동하다 격자 밖을 벗어났을 때 미로를 탈출한 것
char map[102][102];
int dir;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int t;

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

bool findRight(int x, int y, int dir) {

    if(dir == 0) {
        if(map[x + 1][y]  == '#') {
            return true;
        }
        return false;
    }   
    else if(dir == 1) {
        if(map[x][y - 1]  == '#') {
            return true;
        }
        return false;
    }
    else if(dir == 2) {
        if(map[x - 1][y]  == '#') {
            return true;
        }
        return false;
    }
    else {
        if(map[x][y + 1]  == '#') {
            return true;
        }
        return false;
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    cin >> x >> y;
    x--, y--;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // print();

    for(int i = 0; i < n*n; i++)  {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        bool right = findRight(nx, ny, dir);

        if(!InRange(nx, ny)) {
            // cout << nx << ' ' << ny << '\n';
            cout << t + 1;
            return 0;
        }

        if(InRange(nx, ny) && map[nx][ny] == '.') {
        // if(InRange(nx, ny) && map[nx][ny] == '.' && right) {
            if(right) {
                x = nx;
                y = ny;
                map[x][y] = '9';
                t++;
            }
            else {
                x = nx;  
                y = ny;
                map[x][y] = '9';
                t++;
                dir = (dir + 1) % 4;
                continue;
            } 
        }

        if(map[nx][ny] == '#') {
            dir = (dir + 3) % 4;
        }
    }
    // print();
    //cout << x << ' ' << y << '\n';
    cout << -1; 
    return 0;
}