#include <iostream>
#include <algorithm>

using namespace std;

char d;
int mov, n;
pair<int, int> cur;

// W, S, N, E 순서
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'W', 'S', 'N', 'E'};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    while(n--) {
        cin >> d >> mov;
        
        for(int i = 0; i < 4; i++) {
            if(dir[i] == d) {
                cur.first = cur.first + (dx[i] * mov);
                cur.second = cur.second + (dy[i] * mov);
            }
        }
    }

    cout << cur.first << ' ' << cur.second;
    return 0;
}