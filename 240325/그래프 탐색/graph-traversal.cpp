#include <iostream>
#include <vector>

using namespace std;

int n, m;

int map[1001][1001];
bool visited[1001];
int answer;

void print() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int x) {
    visited[x] = true;
    // if(visited[x][y] == true) {
    //     return;
    // }
   
    for(int i = 1; i <= n; i++) {
        if(!visited[i] && map[x][i] == 1) {
            answer++;
            dfs(i);
            visited[i] = true;
        }
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         if(!visited[i][j] && map[i][j] == 1) {
    //             dfs(i, j);
    //         }
    //     }
    // }
    dfs(1);
    cout << answer;
    return 0;
}