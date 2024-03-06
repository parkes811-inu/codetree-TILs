#include <iostream>
using namespace std;
int n, m, q;
int map[102][102];
int temp[102][102];
int r1, c1, r2, c2;

void toMove(int r1, int c1, int r2, int c2) {

    int tmp = map[r1][c1];

		// left
		for (int row = r1; row <= r2 - 1; row++) {
			map[row][c1] = map[row + 1][c1];
		}

		// down
		for (int col = c1; col <= c2 - 1; col++) {
			map[r2][col] = map[r2][col + 1];
		}

		// right
		for (int row = r2; row >= r1 + 1; row--) {
			map[row][c2] = map[row - 1][c2];
		}

		// top
		for (int col = c2; col >= c1 + 1; col--) {
			map[r1][col] = map[r1][col - 1];
		}

		map[r1][c1 + 1] = tmp;
}


bool InRange(int x, int y) {
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}

void windCheck() {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            int t = map[i][j];
            int cnt = 1;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(InRange(nx, ny)) {
                    t = t + map[nx][ny];
                    cnt++;
                }
            }
            temp[i][j] = t / cnt;
        }
    }

    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];            
        }
    }

    for(int i = 0; i < q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        toMove(r1, c1, r2, c2);
        windCheck();
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << map[i][j] << ' ';            
        }
        cout << '\n';
    }
    return 0;
}