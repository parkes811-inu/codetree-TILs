#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> answer;
string s;
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> s;
        answer.push_back(s);
    }

    sort(answer.begin(), answer.end());

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}