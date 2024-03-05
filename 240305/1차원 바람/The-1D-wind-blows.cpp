#include <iostream>

using namespace std;
int n, m, q, start;
char d;
int map[102][102];

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
        //cout << 'R';
        int temp = map[start][1];
        for(int j = 1; j <= m; j++) {
            map[start][j] = map[start][j + 1];
        }
        map[start][m] = temp;
    }
}

bool findNext(int x, int y) {
    //if(y < 1 || y > n) return false;
    for(int i = 1; i <= m; i++) {
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
        else if(d == 'L') d = 'R';

        char d1, d2;
        d1 = d; d2 = d;

        while(up > 0) {
            if(findNext(up, up - 1) == false) break;

            if(findNext(up, up - 1)) {
                moveTo(up - 1, d1);
                if(d1 == 'R') d1 = 'L';
                else if(d1 == 'L') d1 = 'R';
            }
            up--;
        }

        while(down <= n) {
            if(findNext(down, down + 1) == false) break;

            if(findNext(down, down + 1)) {
                moveTo(down + 1, d2);
                if(d2 == 'R') d2 = 'L';
                else if(d2 == 'L') d2 = 'R';
            }
            down++;
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