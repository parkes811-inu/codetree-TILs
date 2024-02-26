#include <iostream>

using namespace std;

int n, m;
int map[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool InRange(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y <= n);
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        int cnt = 0;

        cin >> x >> y;
        map[x][y] = 1;
        
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(InRange(nx, ny) && map[nx][ny] == 1) {
                cnt++;
            }
        }

        if(cnt == 3) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }    
    return 0;
}