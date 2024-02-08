#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int age;
    char gender;
    for(int i = 0; i < 2; i++) {
        cin >> age >> gender;

        if(age > 19 && gender == 'M') {
            cout << "1";
            return 0;
        }     
    }

    cout << "0";

    return 0;
}