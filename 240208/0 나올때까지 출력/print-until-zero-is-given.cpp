#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

int main() {
    // 여기에 코드를 작성해주세요.
    while(1) {
        int temp;
        cin >> temp;

        if(temp == 0) {
            for(int i = 0; i < a.size(); i++) {
                cout << a[i] << '\n';
            }
            break;
        }
        a.push_back(temp);
    }
    return 0;
}