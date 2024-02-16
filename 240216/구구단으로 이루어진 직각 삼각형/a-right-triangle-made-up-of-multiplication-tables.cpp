#include <iostream>

using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n - i + 1; j++) {
            cout << i << " * " << j << " = " << i * j;
            if(j != n - i + 1) {
                cout << " / ";
            }
        }
        cout << '\n';
    }
    return 0;
}