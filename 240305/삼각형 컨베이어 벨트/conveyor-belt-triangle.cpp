#include <iostream>

using namespace std;

int n, t;
int map[201][201];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < t; i++) {
        int first = map[0][n - 1];
        int second = map[1][n - 1];
        int third = map[2][n - 1];

        for(int j = n - 1; j > 0; j--) {
            map[0][j] = map[0][j - 1];
        }
        map[0][0] = third;

        for(int j = n - 1; j > 0; j--) {
            map[1][j] = map[1][j - 1];
        }
        map[1][0] = first;

        for(int j = n - 1; j > 0; j--) {
            map[2][j] = map[2][j - 1];
        }
        map[2][0] = second;

    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}