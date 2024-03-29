#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
bool visitedDFS[101][101] = {false, };
bool visitedBFS[101][101] = {false, };
int dist[101][101];
int answer = -1;
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> wall;

int n, k;
int r1, c1, r2, c2;

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

void print() {

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "-----------------------------------------\n";
}

void bfs() {
    while(!q.empty()) {
       
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx == r2 && ny == c2) {
                dist[nx][ny] = dist[x][y] + 1;
                answer = dist[nx][ny];
                //cout << dist[r2][c2];
                return;
            }
            if(InRange(nx, ny) && !visitedBFS[nx][ny] && map[nx][ny] == 0) {
                visitedBFS[nx][ny] = true;
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
} 

void init() {
    while(!q.empty()) {
        q.pop();
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = 0; 
            visitedBFS[i][j] = false; 
        }
    }
    // 시작 지점의 dist를 0으로 초기화
    dist[r1][c1] = 0;
}

void dfs(int cnt) {
    if(cnt == k) {
        init();
        q.push({r1, c1});
        visitedBFS[r1][c1] = true;
        bfs();
        //print();
        return;
    }

    for(int i = 0; i < wall.size(); i++) {
        if(!visitedDFS[wall[i].first][wall[i].second]) {
            map[wall[i].first][wall[i].second] = 0;
            visitedDFS[wall[i].first][wall[i].second] = true;
            dfs(cnt + 1);
            visitedDFS[wall[i].first][wall[i].second] = false;
            map[wall[i].first][wall[i].second] = 1;
        }
    }
    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                wall.push_back({i, j});
            }
        }
    }
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    dist[1][1] = 0;
    dfs(0);

    cout << answer;

    return 0;
}