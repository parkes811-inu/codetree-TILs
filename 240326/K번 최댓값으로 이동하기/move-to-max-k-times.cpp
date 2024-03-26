#include <iostream>
#include <queue>

using namespace std;

int n, k;
pair<int, int> cur;

queue<pair<int, int>> q;

int map[101][101];
bool visited[101][101];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

void bfs() {

    while(!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx, ny) && !visited[nx][ny] &&
            map[x][y] > map[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return;
}
int main() 
{
    // 여기에 코드를 작성해주세요.

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    cur.first = x, cur.second = y;

    for(int i = 0; i < k; i++) {
        if (!visited[cur.first][cur.second]) {
            visited[cur.first][cur.second] = true;
            q.push({cur.first, cur.second});
            bfs();
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(visited[i][j] && map[i][j] < map[cur.first][cur.second]) {
                    answer = max(answer, map[i][j]);
                    cur.first = i;
                    cur.second = j;
                    break;
                }
            }
        }
    }

    
    cout << answer <<'\n';
    cout << cur.first << ' ' << cur.second;
    return 0;
}