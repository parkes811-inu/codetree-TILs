#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> bottle(3);

void moveWater(int cur, int next) {

    if(bottle[cur].second > bottle[next].first) {
        bottle[cur].second = bottle[cur].second - bottle[next].first;
        bottle[next].second = bottle[next].first;
        return;
    }
    bottle[next].second = bottle[next].second + bottle[cur].second;
    bottle[cur].second = bottle[cur].second - bottle[cur].second;
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