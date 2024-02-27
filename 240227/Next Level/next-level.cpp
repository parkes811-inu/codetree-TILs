#include <iostream>
using namespace std;
pair<string, int> a, b;

int main() {
    // 여기에 코드를 작성해주세요.
    a.first = "codetree";
    a.second = 10;

    b.first = "codetree";
    b.second = 10;

    string temp;
    int num;
    cin >> temp >> num;

    b.first = temp;
    b.second = num;

    cout << "user " << a.first << " lv " << a.second << '\n';
    cout << "user " << b.first << " lv " << b.second;
    
    return 0;
}