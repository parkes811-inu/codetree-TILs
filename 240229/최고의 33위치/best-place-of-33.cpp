#include <iostream>

using namespace std;
int n;
int cnt = 0;

int map[21][21];

int find33(int x, int y) {
    int cnt = 0;

    for(int i = x; i < x + 3; i++) {
        for(int j = y; j < y + 3; j++) {
            if(map[i][j] == 1) {
                cnt++;
            }
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

    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < n - 2; j++) {
            cnt = max(cnt, find33(i, j));
        }
    }

    cout << cnt;
    return 0;
}