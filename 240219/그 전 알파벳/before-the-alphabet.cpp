#include <iostream>
using namespace std;
char a;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    if(a == 'a') {
        a = 'z';
        cout << a;
        return 0;
    }
    cout << --a;
    return 0;
}