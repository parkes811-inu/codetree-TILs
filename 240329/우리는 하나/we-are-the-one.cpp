#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, u, d;

int map[9][9];
queue<pair<int, int>> q;

bool visitedDFS[9][9];
bool visitedBFS[9][9];
vector<pair<int, int>> list;

int answer = 1;
int temp = 1;
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void print() {

    for(int i = 0; i < list.size(); i++) {
        cout << list[i]. first << ' ' << list[i].second << ' ';
    }
    cout << '\n';
}

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visitedBFS[i][j] = false;
        }
    }
    temp = k;
}

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

            if(InRange(nx, ny) && !visitedBFS[nx][ny] &&
                abs(map[x][y] - map[nx][ny]) >= u && 
                abs(map[x][y] - map[nx][ny]) <= d) {
                    visitedBFS[nx][ny] = true;
                    temp = temp + 1;
                    q.push({nx, ny});
                }
        }
    }
}
void dfs(int cnt) {
    if(cnt == k) {
        // print();
        init();
        for(int i = 0; i < list.size(); i++) {
            visitedBFS[list[i].first][list[i].second] = true;
            q.push({list[i].first, list[i].second});
            bfs();
        }
        answer = max(answer, temp);
        return;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visitedDFS[i][j]) {
                visitedDFS[i][j] = true;
                list.push_back({i , j});
                dfs(cnt + 1);
                list.pop_back();
                visitedDFS[i][j] = false;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k >> u >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0);
    cout << answer;
    return 0;
}