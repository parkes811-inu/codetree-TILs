#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, sum = 0, answer = 0;
    cin >> n;
    for(int i = 1; i <= 100; i++) {
        sum = sum + i;
        if(sum > n) {
            answer = i;
            break;
        }
    }
    cout << answer;
    return 0;
}