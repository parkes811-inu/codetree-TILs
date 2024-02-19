#include <iostream>
using namespace std;
int n;
int map[101][101];
int cnt = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return false;
    }
    return true;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (isRange(nx, ny) && map[nx][ny] == 1) {
                    count++;
                }
            }
            if (count >= 3) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}