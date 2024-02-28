#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// first = distance, second = num
vector<pair<int, int>> dist;
int n, x, y;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        dist.push_back({ abs(x) + abs(y), i });
    }

    sort(dist.begin(), dist.end(), cmp);

    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i].second << '\n';
    }
    return 0;
}