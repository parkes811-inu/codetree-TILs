#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<pair<int, int>> list;
vector<int> answer(10001);
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        list.push_back({a, i + 1});
    }
    sort(list.begin(), list.end(), cmp);

    for(int i = 0; i < n; i++) {
        answer[list[i].second] = i + 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << answer[i] << ' ';
    }
   
    return 0;
}