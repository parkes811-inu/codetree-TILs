#include <iostream>
using namespace std;
string a, b;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    if(a + b == b + a) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}