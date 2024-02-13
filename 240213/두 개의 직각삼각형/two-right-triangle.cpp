#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        
        for(int j = i; j < n; j++) {
            cout << "*";
        }
        for(int x = 0; x < i * 2; x++) {
            cout << ' ';
        }
        for(int k = n - i; k > 0; k--) {
            cout << "*";  
        }
        cout << '\n';
    }
  
    return 0;
}