#include <iostream>

using namespace std;

string s;
char ch;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    ch = s[1];

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ch) {
            s[i] = s[0];
        }
    }
    cout << s;
    return 0;
}