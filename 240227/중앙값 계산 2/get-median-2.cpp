#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> _list;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        _list.push_back(temp);

        sort(_list.begin(), _list.end());

        if(i % 2 == 0) {
            cout << _list[i/2] << ' ';
        }

    }

    return 0;
}