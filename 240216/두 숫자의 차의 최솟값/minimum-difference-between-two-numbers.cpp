#include <iostream>
using namespace std;
int arr[10];
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    int answer = 999;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 1; j < n; j++) {
            if(i == j) {
                continue;
            }
            if( arr[j] > arr[i] && arr[j] - arr[i] < answer) {
                answer = arr[j] - arr[i];
            }
        }
    }
    cout << answer;
    return 0;
}