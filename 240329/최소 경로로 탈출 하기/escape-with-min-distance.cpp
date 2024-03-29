#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[101][101];
int dist[101][101];
bool visited[101][101] = {false, };
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= m);
}

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx, ny) && !visited[nx][ny] && map[nx][ny] == 1) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    dist[1][1] = 0;
    visited[1][1] = true;
    q.push({1, 1});
    bfs();    

    if(!visited[n][m]) {
        cout << -1; 
        return 0;
    }
    cout << dist[n][m];
    return 0;
}