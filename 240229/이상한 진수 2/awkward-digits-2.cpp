#include <iostream>
#include <cmath>
using namespace std;

string s;
int answer;
bool checkZero = false;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            checkZero = true;
            break;
        }
    }
    if(checkZero == false) {
        for(int i = 0; i < s.size(); i++) {
            answer = answer + pow(2, s.size() - 1 - i);
        }
        cout << answer;
        return 0;
    }


    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            s[i] = '1';
            break;
        }
    }

    answer = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            answer = answer + pow(2, s.size() - 1 - i);
        }
    }
    cout << answer;
    return 0;
}