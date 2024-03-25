#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> answer;
int cnt;

int map[26][26];
bool visited[26][26] = {false, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx, ny) && map[nx][ny] == 1 &&
        !visited[nx][ny]) {
            visited[nx][ny] = true;
            cnt++;
            dfs(nx, ny);
        }
    }
    
    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && map[i][j] == 1) {
                visited[i][j] = true;
                cnt = 1;
                dfs(i, j);
                answer.push_back(cnt);
            }
        }
    }
    cout << answer.size() << '\n';

    sort(answer.begin(), answer.end());

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] / 2 << '\n';
    }

    return 0;
}