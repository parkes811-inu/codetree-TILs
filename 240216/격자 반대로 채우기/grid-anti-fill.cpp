#include <iostream>

using namespace std;
int num = 1;
int n;
int arr[10][10];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = n - 1; i >= 0; i--) {
        if (i % 2 != 0) {
            for(int k = n - 1; k >= 0; k--) {
                arr[k][i] = num++;
            }
        }
        else {
            for(int j = 0; j < n; j++) {
                arr[j][i] = num++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}