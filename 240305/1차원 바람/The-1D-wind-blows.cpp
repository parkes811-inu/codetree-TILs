#include <iostream>

/*
    전파 조건
    1. 현재 행과 나아가려는 행을 비교했을 떄,
    단 하나라도 같은 열에 같은 숫자가 있는 경우 
    
    2. 같은 숫자가 하나도 없거나, 전파가 끝에 
    다다른 경우 전파 종료
    
    ** 전파가 현재 행이 밀렸던 반대 방향으로 
    한 칸씩 밀리게 된다.
    
*/
using namespace std;
int n, m, q, start;
char d;
int dir[2];
int map[101][101];

void moveTo(int start, char dir) {
    // for (int i = start 부터 1까지 or n 까지)
    // d = 'R' or 'L'로 계속 변환 ?
    if(dir == 'L') {
        int temp = map[start][m];
        for(int j = m; j > 0; j--) {
            map[start][j] = map[start][j - 1];
        }
        map[start][1] = temp;
    }

    if(dir == 'R') {
        int temp = map[start][1];
        for(int j = 1; j <= m; j++) {
            map[start][j] = map[start][j + 1];
        }
        map[start][m] = temp;
    }
}

bool findNext(int x, int y) {
    if(y < 1 || y > n) return false;
    for(int i = 0; i < m; i++) {
        if(map[x][i] == map[y][i]) {
            return true;
        }
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        cin >> start >> d;
        moveTo(start, d);
        int up = start;
        int down = start;
        if(d == 'R') d = 'L';
        if(d == 'L') d = 'R';
        char d1, d2;
        d1 = d; d2 = d;
        while(up >= 1) {
        if(findNext(up, up - 1) == false) break;
        if(findNext(up, up - 1)) {
            moveTo(up - 1, d1);
            if(d1 == 'R') d1 = 'L';
            else if(d1 == 'L') d1 = 'R';
        }
        up = up - 1;
        }
        while(down <= n) {
            if(findNext(down, down + 1) == false) break;
        if(findNext(down, down + 1)) {
            moveTo(down + 1, d2);
            if(d2 == 'R') d2 = 'L';
            else if(d2 == 'L') d2 = 'R';
        }
        down = down + 1;

        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}