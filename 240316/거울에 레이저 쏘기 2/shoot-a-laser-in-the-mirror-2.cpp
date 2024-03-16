#include <iostream>
#include <vector>

using namespace std;

int N, K;
char grid[1001][1001];
int dx[] = {-1, 0, 1, 0}; // 위, 오른쪽, 아래, 왼쪽
int dy[] = {0, 1, 0, -1};

int reflect(int direction, char mirror) {
    if (mirror == '\\') {
        if(direction == 0) return 1;
        if(direction == 1) return 0;
        if(direction == 2) return 3;
        if(direction == 3) return 2;
    } else { // mirror == '/'
        if(direction == 0) return 1;
        if(direction == 1) return 0;
        if(direction == 2) return 3;
        if(direction == 3) return 2;
    }
    return -1; // should not reach here
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> K;

    int x, y, direction;
    if(K <= N) {
        x = 0;
        y = K - 1;
        direction = 2; // 아래로
    } else if(K <= 2*N) {
        x = K - N - 1;
        y = N - 1;
        direction = 3; // 왼쪽으로
    } else if(K <= 3*N) {
        x = N - 1;
        y = N - (K - 2*N) - 1;
        direction = 0; // 위로
    } else {
        x = 4*N - K;
        y = 0;
        direction = 1; // 오른쪽으로
    }

    int count = 0;
    while(x >= 0 && x < N && y >= 0 && y < N) {
        direction = reflect(direction, grid[x][y]);
        x += dx[direction];
        y += dy[direction];
        count++;
    }

    cout << count << '\n';

    return 0;
}