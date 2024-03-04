#include <iostream>
using namespace std;
int n;
char a[101];
int cnt;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++) {    
        cin >> a[i];
    }

    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < n - 1; j++) {
            for(int k = 0; k < n; k++) {
                if(i == j || i == k || j == k) {
                    continue;
                }
                if(a[i] == 'C' && a[j] == 'O' && a[k] == 'W') {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}