#include <iostream>
#include <vector>
using namespace std;
string s[3];
int Max = 0;
int Min = 999;
int main() {
    // 여기 코드를 작성해주세요.
    for(int i = 0; i < 3; i++) {
        cin >> s[i];
        if(s[i].size() > Max) {
            Max = s[i].size();
        }
        if(s[i].size() < Min) {
            Min = s[i].size();
        }
    }
    cout << Max - Min;
    return 0;
}