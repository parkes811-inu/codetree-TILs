#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
string t;
int cnt = 0;
vector<string> _list;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> k >> t;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        bool flag = false;
        for(int j = 0; j < t.size(); j++) {
            if(temp[j] == t[j]) {
                cnt++;
            }
        }
        if(cnt == t.size()) {
            _list.push_back(temp);
        }
        cnt = 0;
    }
    sort(_list.begin(), _list.end());
    cout <<_list[k-1];
    return 0;
}