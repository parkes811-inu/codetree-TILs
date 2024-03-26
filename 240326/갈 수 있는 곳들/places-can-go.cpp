#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;

int map[102][102];
bool visited[102][102];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;

int answer;

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

void bfs(int x, int y) {

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(InRange(nx, ny) && !visited[nx][ny] 
            && map[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                map[nx][ny] = 9;
                answer++;
            }
        }

    }

}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        if(!visited[x][y]) {
            visited[x][y] = true;    
            q.push({x, y});
            answer++;
            bfs(x, y);
        }
    }
 
    cout << answer << '\n';

    return 0;
}