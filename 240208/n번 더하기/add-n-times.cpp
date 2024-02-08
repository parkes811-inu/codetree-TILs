#include <iostream>
using namespace std;

int a, n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> n;

    for(int i = 0; i < n; i++) {
        a = a + n;
        cout << a << '\n';
    }
    return 0;
}