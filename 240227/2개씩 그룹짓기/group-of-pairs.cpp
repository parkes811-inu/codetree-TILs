#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> num;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < 2 * n; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());

    int max = -999;
    for(int i = 0; i < n; i++) {
        int cur = num[i] + num[2 * n - i];
        if(cur > max) {
            max = cur;
        }
    }
    cout << max;
    return 0;
}