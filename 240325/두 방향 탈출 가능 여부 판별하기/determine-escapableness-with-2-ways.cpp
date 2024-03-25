#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[101][101];
bool visited[101][101] = {false, };
int answer;
// right, down
int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int x, int y) {

    for(int i = 0; i < 2; i++) { 
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(!InRange(nx, y) || map[nx][ny] == 0 ||
            visited[nx][ny] == true) {
            continue;
        }

        visited[nx][ny] = true;
        dfs(nx, ny);
    }
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cin >> map[i][j];
    //     }
    // }
    visited[0][0] = true;
    dfs(0, 0);

    answer = visited[n - 1][m - 1];
    cout << answer;    
    return 0;
}