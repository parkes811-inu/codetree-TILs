#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<char,int>> list;

bool cmp(pair<char,int> a, pair<char, int> b) {
    if(a.second < b.second) {
        return true;
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    char a; int b;

    for(int i = 0; i < 5; i++) {
        cin >> a >> b;
        list.push_back(make_pair(a, b));
    }

    sort(list.begin(), list.end(), cmp);
    cout << list[0].first << ' ' << list[0].second;
    return 0;
}