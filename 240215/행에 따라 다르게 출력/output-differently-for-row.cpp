#include <iostream>
using namespace std;
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i % 2 == 0) {
                num = num + 1;
            }
            else {
                num = num + 2;
            }
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}