#include <iostream>
#include <vector>

using namespace std;
int n, m, t;
vector<pair<int, int>> marble;

int map[22][22];
int count[22][22];
int nextCount[22][22];
int answer;
// 상하좌우 순서
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            nextCount[i][j] = 0;
        }
    }
}
void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //cout << nextCount[i][j] << ' ';
            if(nextCount[i][j] == 1) {
                answer++;
            }
        }
        //cout << '\n';
    }
}
bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

pair<int, int> moveMarble(int x, int y) {
    pair<int, int> next;
    int max = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx, ny) && max < map[nx][ny]) {
            max = map[nx][ny];
            next = make_pair(nx, ny);
        }
    }
    return next;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        marble.push_back({x - 1, y - 1});        
    }

    while(t--) {
        init(); // step1.

        for(int i = 0; i < marble.size(); i++) { // step2-2.
            pair<int, int> next = 
                    moveMarble(marble[i].first, marble[i].second);

            nextCount[next.first][next.second]++;        
        }
        for(int i = 0; i < marble.size(); i++) {
            marble.pop_back();
        }
        // step2-1.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(nextCount[i][j] == 1) {
                    marble.push_back({i, j});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(nextCount[i][j] > 1) {  // step4.
                    nextCount[i][j] = 0;  // step3.
                }
            }
        }
        
    }
    print();
    //cout << "======================\n";
    cout << answer;
    return 0;
}