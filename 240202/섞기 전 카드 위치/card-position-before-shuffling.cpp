#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second < b.second) {
        return true;
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    vector<pair<int, int>> list(n);

    for(int i = 0; i < n; i++) {
        cin >> list[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> list[i].second;
    }
    sort(list.begin(), list.end(), compare);
    for(int i = 0; i < n; i++) {
        cout << list[i].second << '\n';
    }
    return 0;
}