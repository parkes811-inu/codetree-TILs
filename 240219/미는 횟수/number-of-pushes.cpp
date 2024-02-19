#include <iostream>
#include <string>

using namespace std;

string a, b;
int cnt;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++) {
        if(a == b) {
            cnt = i;
            cout << cnt;
            return 0;
        }

        a = a.substr(a.size() - 1) + a.substr(0, a.size() - 1);
    }
    cout << -1;
    return 0;
}