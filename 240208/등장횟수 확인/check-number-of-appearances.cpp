#include <iostream>

using namespace std;
int cnt = 0;
int main() {
    // 여기에 코드를 작성해주세요.
    for(int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;

        if(temp % 2 == 0) {
            cnt++;
        }
    } 
    cout << cnt;
    return 0;
}