#include <iostream>

using namespace std;

int n;
int answer;

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n;
    int sum = 0;
    int a = n / 10;
    int b = n % 10;

    if (n == 0) {
        cout << 1;
        return 0;
    }
    while(1) {

        if(n == sum) {
            break;
        }

        sum = a + b;
        sum = ((a + b) % 10) + (b * 10);
        //cout << sum << '\n';
        answer++;

        a = sum / 10;
        b = sum % 10;
    }
    cout << answer;
    return 0;
}