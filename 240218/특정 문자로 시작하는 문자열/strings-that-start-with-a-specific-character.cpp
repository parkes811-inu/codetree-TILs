#include <iostream>
using namespace std;
float avg = 0.0;
int cnt, n;
string s[21];   
char c;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;    
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cin >> c;
    for(int i = 0; i < n; i++) {
        if(s[i][0] == c) {
            cnt++;
            avg = avg + (float) s[i].size();
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << cnt << ' ';
    cout << avg / float(cnt) << '\n';
    return 0;
}