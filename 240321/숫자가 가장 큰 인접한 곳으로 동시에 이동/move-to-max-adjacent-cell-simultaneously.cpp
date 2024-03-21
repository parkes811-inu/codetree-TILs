#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t;
vector<pair<int, int>> marbles;
int grid[22][22];
// 상하좌우 순서
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void simulate() {
    vector<vector<int>> count(n, vector<int>(n, 0));
    for (auto &marble : marbles) {
        int x = marble.first, y = marble.second;
        int max_val = -1;
        pair<int, int> next_pos = {x, y};

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (in_range(nx, ny) && grid[nx][ny] > max_val) {
                next_pos = {nx, ny};
                max_val = grid[nx][ny];
            }
        }
        
        count[next_pos.first][next_pos.second]++;
    }

    marbles.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (count[i][j] == 1) {
                marbles.push_back({i, j});
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        marbles.push_back({x - 1, y - 1});
    }
    
    while (t--) {
        simulate();
    }

    cout << marbles.size() << endl;
    return 0;
}