#include <iostream>
using namespace std;
string s;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    for(int i = s.size(); i > 0; i--) {
        if(i % 2 != 0) {
            cout << s[i];
        }
    }
    return 0;
}