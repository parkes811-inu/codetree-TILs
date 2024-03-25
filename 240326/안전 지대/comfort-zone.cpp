#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> areas;

int map[51][51];
bool visited[51][51];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m); // m으로 수정
}

int dfs(int x, int y) {
    visited[x][y] = true;
    int area = 1; // 현재 칸을 포함해야 하므로 1부터 시작

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx, ny) && map[nx][ny] > 0 && !visited[nx][ny]) {
            area += dfs(nx, ny);
        }
    }

    return area;
}

void init(int k) {
    fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(bool), false); // 방문 배열 초기화

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            map[i][j] = map[i][j] > k ? map[i][j] : 0; // k 이하면 0으로 설정
        }
    }
}

int main() {
    cin >> n >> m;
    int maxHeight = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            maxHeight = max(maxHeight, map[i][j]); // 가장 높은 높이 갱신
        }
    }

    int maxAreaCount = 0, resultK = 1;

    for(int k = 1; k <= maxHeight; k++) {
        init(k); // 맵 초기화
        int areaCount = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] > 0 && !visited[i][j]) {
                    dfs(i, j);
                    areaCount++;
                }
            }
        }

        if(areaCount > maxAreaCount) {
            maxAreaCount = areaCount;
            resultK = k;
        }
    }

    cout << resultK << " " << maxAreaCount <<'\n';
    
    return 0;
}