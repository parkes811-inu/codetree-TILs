#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            cout << (char)toupper(s[i]);    
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            cout << (char)tolower(s[i]);    
        }
    }    
    

    return 0;
}