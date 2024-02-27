#include <iostream>
#include <algorithm>
using namespace std;

string a, b;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sz = 0;
    if(a.size() > b.size()) {
        for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    }
    else {
        sz = b.size();
        for(int i = 0; i < b.size(); i++) {
        if(a[i] != b[i]) {
            cout << "No";
            return 0;
        }
    }
    }
    cout << "Yes";
    return 0;

    
}