#include <iostream>

using namespace std;

int a, b;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;

    for(int i = a; i <= b; i++) {
        if(i % 2 != 0) {
            cout << i << ' ';
        }
    }
    return 0;
}