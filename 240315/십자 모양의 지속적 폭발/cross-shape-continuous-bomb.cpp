#include <iostream>

using namespace std;
int n, m, c;
int map[202][202];
int temp[202][202];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

void findBomb(int y) {
    // 폭탄을 찾을 떄는 
    // 행이 주어지니까 그 행에서 가장 먼저 0 이상이 나오는 곳을 터트려야 한다.
    int x = -1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(map[i][y] > 0) {
            x = i;
            cnt = map[i][y];
            break;
        }
    }

    if(x == -1) {
        return;
    }

    if(map[x][y] == 1) {
        map[x][y] = 0;
        return;
    }

    map[x][y] = 0;
    for(int d = 0; d < 4; d++) {
        for(int i = 1; i < cnt; i++) {
            int nx = x + dx[d] * i;
            int ny = y + dy[d] * i;

            map[nx][ny] = 0;
        }    
    }
    return;
}

void gravity() {

    for(int i = 1; i <= n; i++) {
        int last = n;
        for(int j = n; j > 0; j--) {
            if(map[j][i] != 0) {
                temp[last--][i] = map[j][i];
            }        
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            map[i][j] = temp[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            temp[i][j] = 0;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> c;

        findBomb(c);
        gravity();
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}