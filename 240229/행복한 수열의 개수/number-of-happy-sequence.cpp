#include <iostream>

using namespace std;

int n, m;
int map[101][101];
int answer;

int main() {
    
    cin >> n >> m;

    if(m == 1) {
        cout << 2 * n;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        int cnt = 1;
        for(int j = 0; j < n - 1; j++) {

            if(map[i][j] == map[i][j + 1]) {
                cnt++;
                if(cnt == m) {
                    answer++;
                }
            }
            else {
                cnt = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int cnt = 1;

        for(int j = 0; j < n - 1; j++) {
            
            if(map[j][i] == map[j + 1][i]) {
                cnt++;
                if(cnt == m) {
                    answer++;
                }
            }
            else {
                cnt = 1;
            }
        }
    }
    
    cout << answer;
}