#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct person {
    string name;
    int kor, eng, math;
};
vector<person> list;

bool cmp(person a, person b) {
    return a.kor + a.eng + a.math < b.kor + b.eng + b.math;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;

        list.push_back({name, kor, eng, math});
    }

    sort(list.begin(), list.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << list[i].name << ' ' << list[i].kor <<
        ' ' << list[i].eng << ' ' << list[i].math << '\n';
    }
    return 0;
}