#include <iostream>
using namespace std;

int a, b;
int result;
int cnt[1000];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    while(a > 1) {
        // cout << a % b << ' ';
        cnt[a%b]++;
        a = a / b;
    }
    for(int i = 0; i < 1000; i++) {
        if(cnt[i] == 0) {
            continue;
        }
        result = result + cnt[i] * cnt[i];
    }
    cout << result;
    return 0;
}