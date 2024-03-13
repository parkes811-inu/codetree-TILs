#include <iostream>
using namespace std;

int n, m, k;
int map[102][102];

int findLocation() {
    for(int i = 1; i <= n; i++) {
        for(int j = k; j <= k + m - 1; j++) {
            if(map[i][j] == 1) {
                // 블록을 놓을 수 없으므로 이전 행을 반환해야 함
                return i - 1;
            }
        }
        // 모든 열을 검사한 후에도 블록을 놓을 수 없는 경우가 없으면,
        // 현재 행에서 블록을 놓을 수 있다는 의미이므로, 계속 진행
    }
    // 마지막 행까지 블록을 놓을 수 있는 경우, n을 반환
    return n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    int idx = findLocation();

    for(int i = k; i <= k + m - 1; i++) {
        map[idx][i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}