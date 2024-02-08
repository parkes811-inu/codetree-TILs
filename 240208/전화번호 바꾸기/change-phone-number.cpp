#include <iostream>
#include <string>

using namespace std;

string s;
string answer;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    string temp1 = "";
    temp1 = temp1 + s[9] + s[10] + s[11]+ s[12];
    string temp2 = "";
    temp2 = temp2 + s[4] + s[5] + s[6]+ s[7];

    s[4] = temp1[0];
    s[5] = temp1[1];
    s[6] = temp1[2];
    s[7] = temp1[3];

    s[9] = temp2[0];
    s[10] = temp2[1];
    s[11] = temp2[2];
    s[12] = temp2[3];

    cout << s;
    return 0;
}