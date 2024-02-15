#include <iostream>
using namespace std;
int a, b;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 2; i <= 8; i++) {
        if(i % 2 != 0) {
            continue;
        }
        for(int j = b; j >= a; j--) {
            cout << j << " * "  <<  i << " = " << j * i;
            if(j != a) {
                cout << " / ";
            }
        }
        cout << '\n';
    }
    return 0;
}