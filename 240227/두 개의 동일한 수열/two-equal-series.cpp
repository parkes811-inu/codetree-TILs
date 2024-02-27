#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;
int n, temp;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        cin >> temp;
        b.push_back(temp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}