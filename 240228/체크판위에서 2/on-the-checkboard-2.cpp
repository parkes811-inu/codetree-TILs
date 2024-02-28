#include <iostream>

using namespace std;
int r, c, cnt;
char map[17][17];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> r >> c;

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            for(int k = i + 1; k < r; k++) {
                for(int l = j + 1; l < c ; l++) {
                    if(map[1][1] != map[i][j] && map[i][j] != map[k][l] && 
                       map[k][l] != map[r][c]) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}