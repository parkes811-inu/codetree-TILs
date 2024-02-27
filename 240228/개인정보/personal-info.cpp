#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
    string name;
    int height;
    double weight;
};

vector<person> list;
bool cmp1(person a, person b) {
    return a.name < b.name;
}

bool cmp2(person a, person b) {
    return a.height > b.height;
}
int main() {
    // 여기에 코드를 작성해주세요.
    for(int i = 0; i < 5; i++) {
        string name;
        int height;
        double weight;

        cin >> name >> height >> weight;

        list.push_back({name, height, weight});
    }

    sort(list.begin(), list.end(), cmp1);

    cout << "name\n"; 
    for(int i = 0; i < 5; i++) {
        cout << list[i].name << ' ' << list[i].height << ' '
        << list[i].weight << '\n';
    }

    cout << '\n';
    sort(list.begin(), list.end(), cmp2);


    cout << "height\n"; 
    for(int i = 0; i < 5; i++) {
        cout << list[i].name << ' ' << list[i].height << ' '
        << list[i].weight << '\n';
    }
    return 0;
}