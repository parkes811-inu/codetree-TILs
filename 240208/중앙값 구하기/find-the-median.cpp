#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> num(3);
    cin >> num[0] >> num[1] >> num[2];

    sort(num.begin(), num.end());

    cout << num[1];
    
    return 0;
}