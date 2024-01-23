#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, p;
    cin >> n >> p;

    vector<int> answer;
    int temp = (n * n) % p;
    answer.push_back(temp);

    while(1) {
        temp = (temp * n) % p;
        if(find(answer.begin(), answer.end(), temp) != answer.end()) {
            cout << answer.size() << ' ';
            break;
        }
        answer.push_back(temp);    
    }    

    // int temp = n * n;
    // temp = temp % p;
    // cout << temp << '\n';

    // temp = temp * n;
    // temp = temp % p;
    // cout << temp << '\n';

    // temp = temp * n;
    // temp = temp % p;
    // cout << temp << '\n';
    return 0;
}