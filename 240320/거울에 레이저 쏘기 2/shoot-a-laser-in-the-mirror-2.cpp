#include <iostream>
#include <vector>

using namespace std;
int n, k;
int dir, x, y;
char map[1002][1002];
int answer;
// 시계 방향
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int findDir(int k) {
    
    for(int i = 1; i <= 4 * n; i++) {
        if(i / 4 == 0) {
            // cout << "i / 4 = 0 : " << i % 4 << ' ';
            x = -1;
            y = i % 4;
            return 0;
        }
        else if(i / 4 == 1) {
            // cout << "i / 4 = 1 : " << i % 4 << ' ';
            x = i % 4;
            y = n;
            return 1;
        }
        else if(i / 4 == 2) {
            // cout << "i / 4 = 2 : " << i % 4 << ' ';
            x = n;
            y = i % 4;
            return 2;
        }
        else {
            // cout << "i / 4 = 3 : " << i % 4 << ' ';
            x = i % 4;
            y = -1;
            return 3;
        }

        // cout << '\n';
    }
    return -1;
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    cin >> k;
    k--;

    // print();

    dir = findDir(k);
    vector<pair<int, int>> cur;
    while(1) {
        x = x + dx[dir];
        y = y + dy[dir];
        cur.push_back({x, y});
        answer++;

        if(x < 0 || y < 0 || x >= n || y >= n) {
            break;
        }

        if(map[x][y] == '\\') {

            if(dir == 0) dir = 3;
            else if(dir == 1) dir = 2;
            else if(dir ==2) dir = 1;
            else 
                dir = 0;
        }

        else if(map[x][y] == '/') {
            if(dir == 0) dir = 1;
            else if(dir == 1) dir = 0;
            else if(dir ==2) dir = 3;
            else 
                dir = 2;
        }
    }
    // print();

    // for(int i = 0; i < cur.size(); i++) {
     
    //     cout << cur[i].first << ' ' << cur[i].second << '\n';
    // }
    cout << answer-1;
    return 0;
}