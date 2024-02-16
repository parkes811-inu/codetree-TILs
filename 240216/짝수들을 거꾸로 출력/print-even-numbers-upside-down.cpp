#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> list;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.push_back(num);
    }

    for(int i = list.size() - 1; i >= 0; i--) {
        if(list[i] % 2 == 0) {
            cout << list[i] << ' ';
        }
    }
    return 0;
}