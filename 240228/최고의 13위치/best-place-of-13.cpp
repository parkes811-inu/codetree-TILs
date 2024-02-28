#include <iostream>
#include <algorithm>

using namespace std;

int map[21][21];
int n;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int max_cnt = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n - 1; j++) {
            int sum = 0;
            for(int k = j; k < j + 3; k++) {
                sum = sum + map[i][k];
            }
            //max_cnt = max(max_cnt, (map[i][j] + map[i][j + 1] + map[i][j + 2]));
            max_cnt = max(max_cnt, sum);
        }
    }
    cout << max_cnt;
    return 0;
}