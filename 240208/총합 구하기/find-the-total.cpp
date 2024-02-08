#include <iostream>

using namespace std;
int sum = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(i % 6 == 0 && i % 8 != 0) {
            sum = sum + i;
        }
    }
    cout << sum;
    return 0;
}