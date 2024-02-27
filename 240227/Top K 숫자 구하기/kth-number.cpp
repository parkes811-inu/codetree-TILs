#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;
int n, k, temp;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        answer.push_back(temp);
    }
    sort(answer.begin(), answer.end());
    cout << answer[k - 1];
    return 0;
}