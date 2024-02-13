#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[5] = {0, };
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < 5; i++) {
        if(arr[i] % 3 != 0) {
            cout << "0";
            return 0;
        }
    }
    cout << "1";
    return 0;
}