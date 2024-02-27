#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int n;

vector<tuple<string, int, int>> list;

bool cmp(tuple<string, int, int> a, tuple<string, int, int> b) {
    return (get<1>(a) < get<1>(b));
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        string name;
        int height, weight;
        cin >> name >> height >> weight;

        list.push_back(make_tuple(name, height, weight));
    }
    sort(list.begin(), list.end(), cmp);
    for(int i = 0; i < n; i++) {
        cout << get<0>(list[i]) << ' ' << get<1>(list[i]) << ' ' << get<2>(list[i]) << '\n';
    }
    return 0;
}