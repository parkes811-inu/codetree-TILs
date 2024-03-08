#include <iostream>

using namespace std;

int n;

int map[102];
int temp[102];
int s, e;
int last_idx;
int last_tempIdx;

void blockMinus(int n, int s, int e) {
    last_idx = n;
    last_tempIdx = n;
    for(int i = 0; i < n; i++) {
        if(i >= s && i <= e) {
            continue;
        }
        temp[i] = map[i];
    }

    for(int i = 0; i < 102; i++) {
        map[i] = 0;
    }

    int idx = 0;

    for(int i = 0; i < n; i++) {

        if(temp[i] != 0) {
            map[idx] = temp[i];
            idx++;
        }
    }
    for(int i = 0; i < 102; i++) {
        temp[i] = 0;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> map[i];
    }

    for(int i = 0; i < 2; i++) {
        cin >> s >> e;
        blockMinus(n - 1, s - 1, e - 1);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(map[i] > 0) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    for(int i = 0; i < n; i ++) {
        if(map[i] != 0) {
            cout << map[i] << '\n';
        }
    }
    return 0;
}