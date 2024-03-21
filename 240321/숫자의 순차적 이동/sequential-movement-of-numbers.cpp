#include <iostream>

using namespace std;

// 1부터 n*n까지 순서대로 8방향 중 가장 큰 값이랑 위치를 변경하기
int n, m;
int map[22][22];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

pair<int, int> findIdx(int cur) {
    pair<int, int> idx;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == cur) {
                idx = {i, j};
                break;
            }
        }
    }
    return idx;
}

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

void simulate() {

    for(int i = 1; i <= n * n; i++) {
        pair<int, int> cur = findIdx(i);
        pair<int, int> change;
        int temp = map[cur.first][cur.second];
        int x = cur.first;
        int y = cur.second;
        int maxValue = -1;

        for(int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(InRange(nx, ny) && map[nx][ny] > maxValue) {
                change = {nx, ny};
                maxValue = map[nx][ny];
            }
        }
        map[cur.first][cur.second] = map[change.first][change.second];
        map[change.first][change.second] = temp;

    }
    
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    while(m--) {
        simulate();
    }
    
    print();
    return 0;
}