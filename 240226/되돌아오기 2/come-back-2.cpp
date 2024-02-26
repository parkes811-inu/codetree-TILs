#include <iostream>
using namespace std;
char d;
string cmd;
int dir;
pair<int, int> cur;

// n, e, s, w
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> cmd;
    for(int i = 0; i < cmd.size(); i++) {

        if(cmd[i] == 'L') {
            dir = (dir - 1 + 4) % 4;
        }
        else if(cmd[i] == 'R') {
            dir = (dir + 1) % 4;
        }
        else if(cmd[i] == 'F') {
            cur.first = cur.first + dx[dir];
            cur.second = cur.second + dy[dir];
        }

        if(cur.first == 0 && cur.second == 0) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}