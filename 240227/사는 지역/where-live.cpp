#include <iostream>
#include <algorithm>

using namespace std;
class person {
    public :
        string name;
        string address;
        string region;

    person() {

    }
    person(string name, string address, string region) {
        this->name = name;
        this->address = address;
        this->region = region;
    } 
};
person people[11];
int n;

bool cmp(person a, person b) {
    if(a.name > b.name) {
        return true;
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        string name, address, region;
        cin >> name >> address >> region;

        people[i] = person(name, address, region);
    }

    int last = 0;
    for(int i = 1; i < n; i++) {
        if(people[i].name > people[last].name)
            last = i;
    }

    cout << "name " << people[last].name << '\n';
    cout << "addr " << people[last].address << '\n';
    cout << "city " << people[last].region;

    return 0;
}