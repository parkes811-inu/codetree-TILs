#include <iostream>

using namespace std;

int a, b;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> b >> a;

    for(int i = b; i >= a; i--) {
        if(i % 2 != 0) {
            cout << i << ' ';
        }
    }
    return 0;
}