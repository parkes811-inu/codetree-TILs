#include <iostream>
#include <queue>

using namespace std;

int n, k;
pair<int, int> cur;

queue<pair<int, int>> q;

int map[102][102];
bool visited[102][102];

int answer;

int start;
int maxNum;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

void bfs() {

    while(!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx, ny) && !visited[nx][ny] && map[nx][ny] < start) {
                if(map[nx][ny] > maxNum) {
                    maxNum = map[nx][ny];
                }
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return;
}

void init() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
    while(!q.empty()) {
        q.pop();
    }
}

int main() 
{
    // 여기에 코드를 작성해주세요.

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    cur.first = x, cur.second = y;

    for(int t = 0; t < k; t++) {
        maxNum = -1;
        visited[cur.first][cur.second] = true;
        q.push({cur.first, cur.second});
        start = map[cur.first][cur.second];
        bfs();
        if(maxNum == -1) {
            break;
        }
        for(int i = 1; i <= n; i++) {
            bool check = true;
            for(int j = 1; j <= n; j++) {
                if(maxNum == map[i][j]) {
                    cur.first = i;
                    cur.second = j;
                    check = false;
                    break;
                }
            }
            if(!check)
                break;
        }

        init();
    }
    cout << cur.first << ' ' << cur.second << '\n';

    return 0;
}