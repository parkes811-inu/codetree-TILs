#include <iostream>
using namespace std;

int n;
int map[102][102];
int dx[4] = {1, 0, -1, 0}; // 아래, 왼쪽, 위, 오른쪽
int dy[4] = {0, -1, 0, 1};

// 방향 변화 정의
// reflectDir[type][currentDir] => 반사판 타입과 현재 방향에 따른 새로운 방향
int reflectDir[3][4] = {
    {0, 0, 0, 0}, // 0은 반사판 없음, 방향 변화 없음
    {1, 0, 3, 2}, // '/' 반사판에서의 방향 변화
    {3, 2, 1, 0}  // '\' 반사판에서의 방향 변화
};

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int moveMarble(int x, int y, int dir) {
    int cnt = 0;
    
    while(true) {
        x += dx[dir];
        y += dy[dir];
        cnt++; // 구슬을 움직임
        
        if (!InRange(x, y)) break; // 격자 밖으로 나가는 경우 게임 종료
        
        if (map[x][y] > 0) { // 반사판에 부딪힌 경우
            dir = reflectDir[map[x][y]][dir]; // 방향 변경
        }
    }

    return cnt; // 격자 밖으로 나가기까지 걸린 시간 반환
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    int answer = 0;
    // 격자의 모든 가능한 시작점에서 구슬을 이동
    for(int i = 0; i < 4 * n; i++) {
        // 여기에 시작점을 결정하는 로직을 추가
        int cnt = moveMarble(시작 x, 시작 y, 시작 방향);
        answer = max(answer, cnt);
    }
    
    cout << answer << endl;
    
    return 0;
}