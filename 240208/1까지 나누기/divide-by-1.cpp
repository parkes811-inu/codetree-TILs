#include <iostream>

using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int cnt = 0;
    int i = 1;
   while(n / i > 1) {
        n = n / i;
        i++;
        cnt++;
    }
    cout << i;
    return 0;
}