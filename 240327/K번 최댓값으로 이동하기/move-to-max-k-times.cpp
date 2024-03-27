#include <iostream>
#include <queue>

using namespace std;

int n, k;
pair<int, int> cur;
int start;

queue<pair<int, int>> q;

int map[101][101];
bool visited[101][101];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

// void bfs() {

//     while(!q.empty()) {

//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();

//         for(int i = 0; i < 4; i++) {
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if(InRange(nx, ny) && !visited[nx][ny] &&
//             map[x][y] > map[nx][ny]) {
//                 visited[nx][ny] = true;
//                 q.push({nx, ny});
//             }
//         }
//     }
//     return;
// }
void bfs() {
    while (!q.empty()) {
        int size = q.size(); // 현재 레벨의 크기
        int maxVal = -1;
        pair<int, int> maxPos;

        for (int s = 0; s < size; ++s) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 시작위치보다 작은 경우 움직일 수 있어.
                if (InRange(nx, ny) && !visited[nx][ny] && map[x][y] > map[nx][ny]) {
                    // 시작 위치 보다는 작고, 그 중에서 가장 큰 경우이면 큐에 푸시
                    if (map[nx][ny] > maxVal) {
                        cout << "tlqkf";
                        maxVal = map[nx][ny];
                        cur.first = maxPos.first;
                        cur.second = maxPos.second;
                        maxPos = {nx, ny};
                    }
                }
            }
        }
        // 최댓값을 가진 칸이 있으면 그 칸으로 이동
        if (maxVal != -1) {
            visited[maxPos.first][maxPos.second] = true;

            q.push(maxPos);
        }
    }
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
    start = map[x][y];

    // cout << start;

    for(int i = 0; i < k; i++) {
        if (!visited[cur.first][cur.second]) {
            visited[cur.first][cur.second] = true;
            q.push({cur.first, cur.second});
            bfs();
        }
    cout << cur.first << ' ' << cur.second;
    return 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(visited[i][j] && map[i][j] < map[cur.first][cur.second]) {
                    cur.first = i;
                    cur.second = j;
                    break;
                }
            }
        }
    }


}