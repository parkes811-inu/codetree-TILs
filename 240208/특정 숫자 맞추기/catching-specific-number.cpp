#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    while(1) {
        int temp;
        cin >> temp;

        if(temp == 25) {
            cout << "Good";
            break;
        }

        if(temp < 25) {
            cout << "Higher\n";
        }

        if(temp > 25) {
            cout << "Lower\n";
        }

    }
    return 0;
}