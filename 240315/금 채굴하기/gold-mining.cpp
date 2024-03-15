#include <iostream>

using namespace std;
int n, m;
int answer;
int map[21][21];

int getK(int k) {
    return (k * k + (k + 1) * (k + 1));
}

int getGold(int x, int y, int k) {
    int gold = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(abs(x - i) + abs(y - j) <= k) {
                gold = gold + map[i][j];
            }
        }
    }

    return gold;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            for(int k = 0; k < 2 * n; k++) {
                int count = getGold(i, j, k);

                if(count * m >= getK(k)) {
                    answer = max(answer, count);
                }
            }
        }
    }
    cout << answer;
    return 0;
}