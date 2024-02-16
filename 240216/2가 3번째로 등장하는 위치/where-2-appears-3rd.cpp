#include <iostream>

using namespace std;
int n;
int arr[101];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int cnt = 0;
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];

        if(arr[i] == 2) {
            cnt++;
        }

        if(cnt == 3) {
            answer = i;
            break;
        }
    }
    cout << answer;
    return 0;
}