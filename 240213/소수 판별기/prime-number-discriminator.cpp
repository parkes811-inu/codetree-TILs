#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        if(n % i == 0 && i == 1 || i == n) {
            cout << "P";
            return 0;
        }
    }
    cout << "C";
    return 0;
}