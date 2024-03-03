#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n;

vector<pair<int, int>> list;
int answer = 2100000;

int main() {

    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        list.push_back({x, y});
    }

    for(int i = 1; i < n - 1; i++) {
        int dist = 0;
        int prev = 0;
        for(int j = 1; j < n; j++) {
            if(i == j) {
                continue;
            }
            dist = dist + abs(list[prev].first - list[j].first)
                        + abs(list[prev].second - list[j].second);
            prev = j;            
        }          
        answer = min(dist, answer);        
    }
    cout << answer;
    return 0;
}