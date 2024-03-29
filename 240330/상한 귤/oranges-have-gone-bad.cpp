#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, k;

int map[101][101];
bool visited[101][101] = {false, };
int dist[101][101] = {999, };
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<pair<int, int>> orange;

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
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
                
                // dist를 증가하는 조건
                dist[nx][ny] = dist[x][y] + 1;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                orange.push_back({i, j});
            }
            if(map[i][j] == 1) {
                //dist[i][j] = -2; // 상하지 않는 귤을 위한 초기값 설정
            } else {
                dist[i][j] = -1; // 빈 칸을 위한 초기값 설정
            }
        }
    }

    // orange.size()
    for(int i = 0; i < orange.size(); i++) {
        visited[orange[i].first][orange[i].second] = true;
        dist[orange[i].first][orange[i].second] = 0;
        q.push({orange[i].first, orange[i].second});
       
    }
    
    bfs();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && map[i][j] == 1) {
               dist[i][j] = -2;
            }
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}