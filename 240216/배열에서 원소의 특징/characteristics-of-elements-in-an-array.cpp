#include <iostream>
using namespace std;
int num;
int arr[10];
int main() {
    // 여기에 코드를 작성해주세요.
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];

        if(arr[i] % 3 == 0) {
            cout << arr[i-1];
            return 0;
        }
    }
    return 0;
}