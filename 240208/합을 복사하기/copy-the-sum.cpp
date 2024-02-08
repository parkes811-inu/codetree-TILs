#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a = 1, b = 2, c = 3;
    a = a + b + c;
    b = a;
    c = a;

    cout << a << " " << b << " " << c << " ";
    return 0;
}