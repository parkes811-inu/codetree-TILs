#include <iostream>

using namespace std;
int n, s;
int answer = 99999;
int sum;
int arr[102];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum = sum + arr[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            int temp = sum - (arr[i] + arr[j]);
            answer = min(answer, abs(temp - s));
        }
    }
    cout << answer;
    return 0;
}