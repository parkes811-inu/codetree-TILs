#include <iostream>

using namespace std;

string a;
int cnt;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;

    for(int i = 0; i < a.size() - 3; i++) {
        for(int j = i + 2; j < a.size() - 1; j++) {
            if(a[i] == '(' && a[i + 1] == '(' && 
                a[j] == ')' && a[j + 1] == ')') {
                    cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}