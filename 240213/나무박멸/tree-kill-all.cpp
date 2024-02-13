#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, m, k, c;
int map[21][21];
bool visited[21][21];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 1-1. 상, 하, 좌, 우 4방향에 나무를 검사
int cntTree(int x, int y) {
    int cnt = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx > n || ny > n || map[x][y] == -1) {
            continue;
        }

        if(map[nx][ny] > 0 && map[x][y] != 0) {
            cnt++;
        }
    }

    return cnt;
}   

// 1. 인접한 나무의 개수 만큼 나무 크기 증가
void GrowTree() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = cntTree(i, j);
            if(cnt > 0) {
                map[i][j] = map[i][j] + cnt;
            }
        }
    }
}

// 2-1. 각 칸의 나무 그 수에서 총 번식이 가능한 칸의 개수만큼 나누어진 만큼 번식
void breedingCnt(int x, int y) {
    int cnt = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx > n || ny > n || map[x][y] == -1) {
            continue;
        }

        if(map[nx][ny] == 0) {
            cnt++;
        }
    }

    

    if(cnt > 0) {
        int plusCnt = map[x][y] / cnt;
        // / 연산으로 나머지는 버림.
        for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 0 || ny < 0 || nx > n || ny > n || map[x][y] <= 0 || 
            map[nx][ny] != 0) {
            continue;
        }

        map[nx][ny] = plusCnt;
    }

    }
    
    return;
}   

// 2. 기존에 있던 나무들은 인접한 4개의 칸 중 벽, 다른 나무, 제초제가 모두 없는 칸에 번식
void breeding() {
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] != 0 ) {
                breedingCnt(i, j);
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k >> c;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    GrowTree();
    cout << "---------------GrowTree() ---------\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    
    breeding();
    cout << "---------------breeding() ---------\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}