#include <iostream>
using namespace std;

string a, b, answer;

int main() {
    // 여기에 코드를 작성해주세요.
    getline(cin, a);
    getline(cin, b);
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == ' ') {
            continue;
        }
        answer = answer + a[i];
    }
    for(int i = 0; i < b.size(); i++) {
        if(b[i] == ' ') {
            continue;
        }
        answer = answer + b[i];
    }
    cout << answer;
    
    return 0;
}