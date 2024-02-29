#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n;

vector<pair<int, int>> list;
int answer = 999;

int main() {

    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        list.push_back({x, y});
    }

    for(int i = 1; i < n - 1; i++) {
        int temp = abs(list[0].first - list[i].first) 
                    + abs(list[0].second - list[i].second);
        for(int j = i + 1; j < n; j++) {
            temp = temp + abs(list[i].first - list[j].first)
                        + abs(list[i].second - list[j].second);
        }          
        if(temp < answer) {
            answer = temp;
        }           
    }
    cout << answer;
    return 0;
}