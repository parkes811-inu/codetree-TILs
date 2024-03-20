#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n, m, t;
vector<pair<int, int>> marbles; // 구슬의 위치
int map[22][22]; // 격자판 정보
int dx[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

// 구슬 이동 및 충돌 처리
void simulate() {
    vector<vector<int>> newPos(n, vector<int>(n, 0));

    for(auto marble : marbles) {
        int x = marble.first, y = marble.second;
        int maxVal = map[x][y];
        pair<int, int> nextMove = {x, y};

        // 인접한 칸 중 최대값을 찾아 이동
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(InRange(nx, ny) && map[nx][ny] > maxVal) {
                nextMove = {nx, ny};
                maxVal = map[nx][ny];
            }
        }

        // 구슬이 이동한 위치에 기록
        if(nextMove != make_pair(x, y)) {
            newPos[nextMove.first][nextMove.second]++;
        } else {
            newPos[x][y]++;
        }
    }

    // 구슬 위치 및 충돌 처리
    marbles.clear();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(newPos[i][j] == 1) { // 충돌 없이 이동한 구슬만 남김
                marbles.push_back({i, j});
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        marbles.push_back({x - 1, y - 1});
    }

    for(int i = 0; i < t; ++i) {
        simulate();
    }

    cout << marbles.size() << endl; // 남은 구슬의 수 출력

    return 0;
}