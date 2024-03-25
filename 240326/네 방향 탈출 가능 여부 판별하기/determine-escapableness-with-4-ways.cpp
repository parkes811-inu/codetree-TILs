#include <iostream>
#include <queue>

using namespace std;

int n, m;
queue<pair<int, int>> q;
int answer;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int map[101][101];
bool visited[101][101] = {false, };

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void bfs(int x, int y) {

    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(cx == n - 1 && cy == m - 1) {
            answer = 1;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(InRange(nx, ny) && map[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    bfs(0, 0);
    cout << answer;
    return 0;
}