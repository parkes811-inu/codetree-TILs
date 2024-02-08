#include <iostream>

using namespace std;
double age;
double answer;
int cnt;

int main() {
    // 여기에 코드를 작성해주세요.
    cout << fixed;
    cout.precision(2);
    while(1) {
        cin >> age;
        if(age < 20 || age > 29) {
            cout << answer / cnt;
            break;
        }
        answer = answer + age;
        cnt++;
    }
    return 0;
}