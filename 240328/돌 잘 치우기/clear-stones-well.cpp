#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
int map[101][101];
bool visited[101][101] = {false, };

vector<pair<int, int>> s_pnts;
vector<pair<int, int>> stones;
queue<pair<int, int>> q;

vector<int> v;

int answer, cnt;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool InRange(int x, int y) {
    return (x > 0 && x <= n && y > 0 && y <= n);
}

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && map[nx][ny] == 0) {
                cnt++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void init() {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
}

void choose(int next) {
    // m개의 돌 선택
    if (v.size() == m) {
        // m개의 돌 치우기
        for (int i = 0; i < m; i++) {
            map[stones[v[i]].first][stones[v[i]].second] = 0;
        }
        init();
        BFS();
        answer = max(answer, cnt);

        for (int i = 0; i < s_pnts.size(); i++) {
            if (!visited[s_pnts[i].first][s_pnts[i].second]) {
                cnt++;
                visited[s_pnts[i].first][s_pnts[i].second] = true;
                q.push({s_pnts[i].first, s_pnts[i].second});
            }
        }

        for (int i = 0; i < m; i++) {
            map[stones[v[i]].first][stones[v[i]].second] = 1;
        }
            
        return;
    }
    
    for (int i = next; i < stones.size(); i++) {
        v.push_back(i);
        choose(i + 1);
        v.pop_back();
    } 
}

int main() {
    cin >> n >> k >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            
            if (map[i][j] == 1) {
                stones.push_back({i, j});
            }
        }
    }
    
    for (int i = 0; i < k; i++) {
        int x, y; 
        cin >> x >> y; 
        s_pnts.push_back({x, y});
    }

    choose(0);
    cout << answer;
}