#include <iostream>
using namespace std;

int n;
char d;
int m, dir;
// n, e, s, w
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int, int> cur;
int answer;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    while(n--) {
        cin >> d >> m;

        if(d == 'N') {
            dir = 0;
        }
        else if(d == 'E') {
            dir = 1;
        }
        else if(d == 'S') {
            dir = 2;
        }   
        else if(d == 'W') {
            dir = 3;
        }

        for(int i = 0; i < m; i++) {
            cur.first = cur.first + dx[dir];
            cur.second = cur.second + dy[dir];
            answer++;
            if(cur.first == 0 && cur.second == 0) {
                cout << answer;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}