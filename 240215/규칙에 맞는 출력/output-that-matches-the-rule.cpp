#include <iostream>
#include <cmath>

using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 1; i <= n; i++)  {
        for(int j = i; j > 0; j--) {
            cout << abs(n - j) + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}