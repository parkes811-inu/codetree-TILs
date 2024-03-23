#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> answer;

void print() {
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
}
void choose(int num) {
    if(num == n + 1) {
        print();
        return;
    }

    for(int i = 1; i <= k; i++) {
        answer.push_back(i);
        choose(num + 1);
        answer.pop_back();
    }
   return;
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k >> n;
    choose(1);
    return 0;
}