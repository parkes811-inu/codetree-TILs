#include <iostream>
#include <string>

using namespace std;

string student[5] = {" ", "John", "Tom", "Paul", "Sam"};
int main() {
    // 여기에 코드를 작성해주세요.

    while(1) {
        int num;
        cin >> num;

        if(num > 4 || num < 1) {
            cout << "Vacancy";
            break;
        }

        cout << student[num] << '\n';
    }
    return 0;
}