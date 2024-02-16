#include <iostream>
using namespace std;

int n;
int a, b;
int sum;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;

        for(int j = a; j <= b; j++) {
            if(j % 2 == 0) {
                sum = sum + j;
            }
        }
        cout << sum << '\n';
        sum = 0;
    }
    return 0;
}