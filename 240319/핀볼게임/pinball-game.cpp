#include <iostream>
using namespace std;

int n;
int map[101][101];
int last;

int answer;
int x, y, dir;
// Down, left, Up, Right
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

void findDir(int start) {
    if(start / n == 0) {
        dir = 0;
        x = 0;
        y = start % n;
    }
    else if(start / n == 1) {
        dir = 1;
        x = start % n;
        y = n - 1;
    }
    else if(start / n == 2) {
        dir = 2;
        x = n - 1;
        y = start % n;
    }
    else {
        dir = 3;
        x = start % n;
        y = 0;
    }
}

int moveMarble(int start) {
    findDir(start);
    int cnt = 1;

    while(true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!InRange(nx, ny)) break; // 격자 밖으로 나가면 종료

        if (map[nx][ny] == 1) { // '/' 반사판
            dir = (dir == 0) ? 3 : (dir == 1) ? 2 : (dir == 2) ? 1 : 0;
        } else if (map[nx][ny] == 2) { // '\' 반사판
            dir = (dir == 0) ? 1 : (dir == 1) ? 0 : (dir == 2) ? 3 : 2;
        }

        x = nx;
        y = ny;
        cnt++;
    }

    return cnt;
}


int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(0);
    
    cin >> n;
    cin.tie();
    cout.tie();

    last = 4 * n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < last; i++) {
        int cnt = moveMarble(i);
        answer = max(cnt, answer);
    }

    cout << answer;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}