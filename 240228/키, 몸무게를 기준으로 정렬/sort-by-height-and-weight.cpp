#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int n;
struct person {
    string name;
    int height;
    int weight;
};

vector<person> list;

bool cmp(person a, person b) {
    if(a.height == b.height) {
        return a.weight > b.weight;
    }
    return a.height < b.height;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++) {
        string name; int height; int weight;
        cin >> name >> height >> weight;
        list.push_back({name, height, weight});
    }

    sort(list.begin(), list.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << list[i].name << ' ' << list[i].height << ' ' << list[i].weight << '\n'; 
    }
    return 0;
}