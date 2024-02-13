#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;

    cin >> n;

    for(int i = 0; i < 2; i++) {

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << "*";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}