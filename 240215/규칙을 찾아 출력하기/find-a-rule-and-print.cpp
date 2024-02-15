#include <iostream>

using namespace std;

int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || i == n - 1) {
            for (int j = 0; j < n; ++j)
                cout << "* ";
        } else {
            cout << "* ";
            for (int j = 1; j < n - 1 ; ++j)
                cout << (i < j + 1 && i < n - 1 ? "  " : "* ");
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}