#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int n;

struct student {
    string name;
    int kor;
    int eng;
    int math;
};

vector<student> list;

bool cmp(student a, student b) {

    if(a.kor == b.kor) {
        if(a.eng == b.eng) {
            return a.math > b.math;            
        }
        return a.eng > b.eng;
    }
    return a.kor > b.kor;
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