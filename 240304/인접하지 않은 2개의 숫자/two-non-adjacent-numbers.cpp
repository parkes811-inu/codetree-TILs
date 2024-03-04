#include <iostream>
#include <cmath>

using namespace std;
int n;
int arr[101];
int answer;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int temp = 0;
        for(int j = i + 1; j < n; j++) {
            if(i == j || abs(i - j) == 1) {
                continue;
            }   
            temp = arr[i] + arr[j];
            answer = max(answer, temp);
        }
    }
    cout << answer;
    return 0;
}