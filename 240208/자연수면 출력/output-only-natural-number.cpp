#include <iostream>

using namespace std;

int a, b;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;

    if(a > 0) {
        for(int i = 0; i < b; i++) {
            cout << a;
        }
    }
    else {
        cout << "0";
    }
    return 0;
}