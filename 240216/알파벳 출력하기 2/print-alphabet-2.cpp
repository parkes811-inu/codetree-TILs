#include <iostream>
#include <string>

using namespace std;
int n;

char alpha = 'A';
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < i + 1; j++) {
            cout << "  ";
        }
        for(int k = 0; k < n - i; k++) {
            cout << alpha << ' ';
            alpha++;
            if(alpha > 'Z') {
                alpha = 'A';
            }
        }
        cout << '\n';
    }

    return 0;
}