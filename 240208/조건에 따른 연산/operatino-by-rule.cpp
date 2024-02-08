#include <iostream>

using namespace std;
int n, cnt;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    while(1) {
        if(n > 1000) {
            cout << n << '\n';
            cout << cnt << '\n';
            break;
        }

        if(n % 2 == 0) {
            n = (n * 3) + 1;
            cnt++;
        }
        if(n % 2 != 0) {
            n = (n * 2) + 2;
            cnt++;
        }
    }
    return 0;
}