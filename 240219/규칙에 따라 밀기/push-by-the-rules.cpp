#include <iostream>
#include <string>

using namespace std;

string a, cmd;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> cmd;

    //cout << a << '\n';
    for(int i  = 0; i < cmd.size(); i++) {
        if(cmd[i] ==  'L') {
            // L 일 때,
            a = a.substr(1, a.size() - 1) + a.substr(0, 1);
            //cout << a << '\n';
        }
        else if(cmd[i] == 'R') {
            // R 일 때,
            a = a.substr(a.size() - 1) + a.substr(0, a.size() - 1);
            //cout << a << '\n';
        }
    }
    cout << a;
    return 0;
}