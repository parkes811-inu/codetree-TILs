#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a = 5, b = 6, c = 7;

    int temp1 = b;
    int temp2 = c;
    b = a;
    a = temp2;
    c = temp1;
    
    cout << a << '\n' << b << '\n' << c;
    return 0;
}