#include <iostream>
#include <queue>

using namespace std;

int dist[101][101];
bool visited[101][101] = {false, };
queue<pair<int, int>> q;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int n;
int r1, c1, r2, c2;
int cnt;

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

void bfs() {

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    q.push({r1, c1});
    visited[r1][c1] = true;
    bfs();

    if(!visited[r2][c2]) {
        cout << -1;
        return 0;
    }
    cout << dist[r2][c2];
    return 0;
}