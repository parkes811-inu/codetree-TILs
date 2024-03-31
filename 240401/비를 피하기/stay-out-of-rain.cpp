#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, h, m, cnt;
int map[101][101];
bool visited[101][101] = {false, };
int dist[101][101];

vector<pair<int, int>> person;
vector<pair<int, int>> escape;
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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

            if(map[nx][ny] == 3) {
                visited[nx][ny] = true;
                cnt++;
                return;
            }

            if(InRange(nx, ny) && !visited[nx][ny] && map[nx][ny] != 1) {
                cnt++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void answer() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

void init() {
    cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //dist[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> h >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                dist[i][j] = -1;
                person.push_back({i ,j});
            }
            if(map[i][j] == 3) {
                escape.push_back({i, j});
            }
        }
    }

    for(int i = 0; i < person.size(); i++) {
        // 사람 수 만큼 bfs를 하고, 출구를 방문한 적 이 잇으면 
        // 멘하턴 거리로 가장 가까운 거리를 넣어줌.
        // 안되면 그냥 -1
        visited[person[i].first][person[i].second] = true;
        q.push({person[i].first, person[i].second});
        bfs();
        for(int j = 0; j < escape.size(); j++) {
            for(int k = 0; k < 4; k++) {
                int nx = person[i].first + dx[k];
                int ny = person[i].second + dy[k];

                if (map[nx][ny] == 1) {
                    dist[person[i].first][person[i].second] = cnt;
                    break;    
                }
            }
            if(visited[escape[j].first][escape[j].second]) {
                
                dist[person[i].first][person[i].second] 
                    = max(cnt, abs(person[i].first - escape[j].first) + 
                    abs(person[i].second - escape[j].second));
            }
        }
        init();
    }

    answer();
    return 0;
}