#include <iostream>

using namespace std;

int n; 
int map[101][101];
int answer;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main(void) {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = 0;

            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if(InRange(nx, ny) && map[nx][ny] == 1) {
                    cnt++;
                }    
            }
            if(cnt >= 3) {
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}