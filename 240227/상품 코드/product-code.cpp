#include <iostream>
using namespace std;

pair<string, int> code1;
pair<string, int> code2;

int main() {
    // 여기에 코드를 작성해주세요.
    string a;
    int b;
    code1.first = "codetree";
    code1.second = 50;
    code2.first = "codetree";
    code2.second = 50;

    cin >> a >> b;

    code2.first = a;
    code2.second = b;

    cout << "product " << code1.second << " is " << code1.first << '\n';
    cout << "product " << code2.second << " is " << code2.first << '\n';

    return 0;
}