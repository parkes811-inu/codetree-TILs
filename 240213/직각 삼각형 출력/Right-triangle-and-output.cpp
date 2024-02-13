#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;

    cin >> n;

    for(int i = 1; i < n*2; i++) {
        if(i % 2 == 0) {
            cout << '\n';
        }
        else {
            for(int j = 0; j < i; j++) {
                cout << "*";
            }
        }
    }
    return 0;
}