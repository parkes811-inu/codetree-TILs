#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;
int n;
int arr[101];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    sort(arr, arr + n, greater<int>());
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}