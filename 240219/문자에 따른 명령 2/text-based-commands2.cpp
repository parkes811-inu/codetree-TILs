#include <iostream>
using namespace std;

string cmd;

//int dx[4] = {0, 1, 0, -1};
//int dy[4] = {-1, 0, -1, 0};
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

int dir = 0;
pair<int, int> cur;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> cmd;
    for(int i = 0; i < cmd.size(); i++) {
        int nx = cur.first + nx;
        int ny = cur.second + ny;
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
    }
    cout << cur.first << ' ' << cur.second;
    return 0;
}