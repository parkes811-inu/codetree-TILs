#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a;
string b;
int count = 01;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    int idx = 0;
    for(int i = 0; i < b.size(); i++) {

        for(int j = 0; j < 26; j++) {
            if(b[idx] == a[j]) {
                idx++;
            }

            if(idx == b.size()) {
            cout << count << '\n';
            return 0;
        }
        }


        count++;
    }
    cout << count;
    //cout << b.size();  
    return 0;
}