#include <iostream>

using namespace std;
string s;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i + 1; j < s.size(); j++) {
            if(s[i] == '(' && s[j] == ')') {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}