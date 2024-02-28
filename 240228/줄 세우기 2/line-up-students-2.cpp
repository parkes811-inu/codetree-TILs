#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int n;
struct student {
    int height;
    int weight;
    int num;
};
vector<student> list;

bool cmp(student a, student b) {
    if(a.height == b.height) {
        return a.weight > b.weight;
    }
    return a.height < b.height;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int height, weight;
        cin >> height >> weight;
        list.push_back({height, weight, i});
    }
    sort(list.begin(), list.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << list[i].height << ' ' <<  list[i].weight <<
        ' ' << list[i].num << '\n';
    }
    return 0;
}