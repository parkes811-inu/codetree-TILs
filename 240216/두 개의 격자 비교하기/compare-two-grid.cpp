#include <iostream>

using namespace std;
int n, m;
int arr1[10][10];
int arr2[10][10];
int answer[10][10];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr1[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr2[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr1[i][j] == arr2[i][j]) {
                answer[i][j] = 0;
            }
            else {
                answer[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}