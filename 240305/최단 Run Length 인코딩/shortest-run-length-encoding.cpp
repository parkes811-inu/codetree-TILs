#include <iostream>

using namespace std;

string s;
string answer;
int cnt = 99999;

void shiftToRight() {

    char temp = s[s.size() - 1];
    for(int i = s.size() - 1; i > 0; i--) {
        s[i] = s[i - 1];
    }
    s[0] = temp;
}

int Encoding() {
    int cnt = 99999;
    int temp = 1;
    char check = '1';

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == s[i + 1]) {
            temp++;
            check++;
        }
        else {
            if(temp == 10) {
                answer = answer + s[i] + "10";
                return answer.size();
            }
            else {
                answer = answer + s[i] + check;
                check = '1';
            }
        }
    }
    return answer.size();
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        int temp = Encoding();
        cnt = min(cnt, temp);
        answer = "";
        shiftToRight();
    }
    cout << cnt;
    return 0;
}