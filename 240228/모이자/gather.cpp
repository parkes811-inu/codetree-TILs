#include <iostream>
#include <cmath>

using namespace std;
int arr[101];
int n;
int mini = 9999999;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            sum = sum + arr[j] * abs(i - j);
        }
        if(sum < mini) {
            mini = sum;
        }
    }
    cout << mini;
    return 0;
}