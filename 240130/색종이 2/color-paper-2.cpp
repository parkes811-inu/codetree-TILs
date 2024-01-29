#include <iostream>
#include <vector>

using namespace std;

int map[501][501];
int count;
void drawing(int _r, int _c) {
    for(int i = _r; i < _r + 10; i++) {
        for(int j = _c; j < _c + 10; j++) {
            map[i][j] = 1;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int x, y;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        drawing(x, y);
    }

    for(int i = 0; i < 501; i++) {
        for(int j = 0; j < 501; j++) {
            if(map[i][j] == 1) {
                // 상하좌우 각 방향에 대해 인접한 셀이 비어있는지 확인
                if (i == 0 || map[i - 1][j] == 0) count++;
                if (i == 500 || map[i + 1][j] == 0) count++;
                if (j == 0 || map[i][j - 1] == 0) count++;
                if (j == 500 || map[i][j + 1] == 0) count++;
            }  
        }
    }
    cout << count;
    return 0;
}