#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

struct person {
    int h, w, cur;
};

vector<person> list;

bool cmp(person a, person b) {
    if(a.h == b.h) {
        if(a.w == b.w) {
            return a.cur < b.cur;
        }
        return a.w > b.w;
    }
    return a.h > b.h;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int h, w;
        cin >> h >> w;
        list.push_back({h, w, i});
    }

    sort(list.begin(), list.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << list[i].h << ' ' << list[i].w << ' ' << list[i].cur << '\n';
    }
    return 0;
}