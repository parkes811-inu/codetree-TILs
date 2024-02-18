#include <iostream>
using namespace std;
string s;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    int idx = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'e') {
            idx = i;
            break;
        }
    } 
    for(int i = 0; i < s.size(); i++) {
        if(i == idx) {
            continue;
        }
        cout << s[i];
    }
    return 0;
}