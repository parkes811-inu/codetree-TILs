#include <iostream>
#include <vector>

using namespace std;

int n;
int r, c;
int map[102][102];
vector<int> answer;

// 상, 하, 좌, 우 순서
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    int x = r;
    int y = c;
    int nx = x;
    int ny = y;
    answer.push_back(map[x][y]);
    int a = 5;

    while (1) {

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (InRange(nx, ny) && map[nx][ny] > map[x][y]) {
                x = nx;
                y = ny;
                answer.push_back(map[nx][ny]);
                break;
            }
            nx = -1;
            ny = -1;
        }

        if (nx == -1 && ny == -1) {
            break;
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}