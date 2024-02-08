#include <iostream>

using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    if(n % 3 == 0) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

    if(n % 5 == 0) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
    return 0;
}