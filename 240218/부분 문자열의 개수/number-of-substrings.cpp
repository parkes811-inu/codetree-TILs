#include <iostream>

using namespace std;

string a, b;
int cnt;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;

    for(int i = 0; i < a.size() - 1; i++) {
        if(b[0] == a[i] && b[1] == a[i + 1]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}