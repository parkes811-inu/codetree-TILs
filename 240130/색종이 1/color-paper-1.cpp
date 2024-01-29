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
                count++;
            }
        }
    }
    cout << count;
    return 0;
}