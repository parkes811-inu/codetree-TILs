#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int cnt = 0;

int main() {
    // 여기에 코드를 작성해주세요.
    while(1) {
        int num;
        cin >> num;
        if(cnt == 3) {
            for(int i = 0; i < 3; i++) {
                cout << a[i] / 2 << '\n';
            }

            break;
        }
        if(num % 2 != 0) {
            continue;
        }
        a.push_back(num);
        cnt++;
    }
    return 0;
}