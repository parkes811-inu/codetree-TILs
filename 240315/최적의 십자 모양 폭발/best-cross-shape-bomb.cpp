#include <iostream>

using namespace std;
int n, answer;

int map[52][52];
int copy_map[52][52];
int temp[52][52];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

void toBomb(int x, int y, int cnt) {

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < cnt; j++) {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;

            if(!(InRange(nx, ny))) {
                continue;
            }
            map[nx][ny] = 0;
        }   
    }

}

int countPair() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { 
            if(i + 1 > n || j + 1 > n) {
                continue;
            }

            if(map[i][j] == map[i][j + 1] && map[i][j] > 0) {
                cnt++;
            }
            if(map[i][j] == map[i + 1][j] && map[i][j] > 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

void gravity() {

    for(int i = 0; i < n; i++) {
        int last = n - 1;
        for(int j = n - 1; j >= 0; j--) {
            if(map[j][i] != 0) {
                temp[last--][i] = map[j][i];
            }        
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            map[i][j] = temp[i][j];
        }
    }


}

void init() {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            map[i][j] = copy_map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = 0;
        }
    }  
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            copy_map[i][j] = map[i][j];
        }
    }
   
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int i = 2, j = 1;
            if(map[i][j] == 1) {
                map[i][j] = 0;
            }
            else {
                toBomb(i, j, map[i][j]);
            }
            gravity();
            int cnt = countPair();
            answer = max(answer, cnt);
            init();
        }
    }
    cout << answer;
    return 0;
}