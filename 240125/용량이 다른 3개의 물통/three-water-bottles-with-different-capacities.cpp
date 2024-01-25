#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> bottle(3);

void moveWater(int cur, int next) {
    // 옮길 수 있는 물의 양 계산
    int amount = min(bottle[cur].second, bottle[next].first - bottle[next].second);

    // 물 옮기기
    bottle[cur].second -= amount;
    bottle[next].second += amount;
}

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i = 0; i < 3; i++) {
        
        cin >> bottle[i].first >> bottle[i].second;

    }

    for(int i = 0; i < 100; i++) {
        moveWater((i%3), (i+1)%3);
    }

    for(int i = 0; i < 3; i++) {
        
        cout << bottle[i].second << '\n';

    }
    return 0;
}