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
    findDir(start); // 초기 위치와 방향 설정
    int cnt = 1; // 격자 안에서 움직인 시간(거리)

    while(true) {
        x += dx[dir];
        y += dy[dir];
        cnt++; // 구슬을 움직임

        // 격자 밖으로 나가는 경우 게임 종료
        if (!InRange(x, y)) return cnt;

        // 반사판에 부딪힌 경우 방향 변경
        if (map[x][y] == 1) {
            // `/` 모양 반사판
            if (dir == 0) dir = 1; // 아래 -> 왼쪽
            else if (dir == 1) dir = 0; // 왼쪽 -> 아래
            else if (dir == 2) dir = 3; // 위 -> 오른쪽
            else if (dir == 3) dir = 2; // 오른쪽 -> 위
        } else if (map[x][y] == 2) {
            // `\` 모양 반사판
            if (dir == 0) dir = 3; // 아래 -> 오른쪽
            else if (dir == 3) dir = 0; // 오른쪽 -> 아래
            else if (dir == 1) dir = 2; // 왼쪽 -> 위
            else if (dir == 2) dir = 1; // 위 -> 왼쪽
        }
    }

    return cnt; // 격자 밖으로 나가기까지 걸린 시간 반환
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