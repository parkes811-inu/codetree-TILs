#include <iostream>

using namespace std;

int a, b, sum = 1;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 1; i <= b; i++) {
        if(i % a == 0) {
            sum = sum * i;
        }
    }
    cout << sum;
    return 0;
}