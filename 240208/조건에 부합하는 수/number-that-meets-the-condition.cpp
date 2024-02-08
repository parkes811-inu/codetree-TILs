#include <iostream>

using namespace std;

int a;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;

    for(int i = 1; i <= a; i++) {
        if(i % 2 == 0 && i % 4 != 0) {
            continue;
        }
        if((i / 8) % 2 == 0) {
            continue;
        }
        if((i % 7) < 4) {
            continue;
        }
        cout << i << ' ';
    }
    return 0;
}