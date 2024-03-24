#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> answer;
int visted[11];
void print() {
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
}

void choose(int cnt, int num) {

    if(cnt == m) {
        print();
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(visted[i] == false && num < i) {
            visted[i] = true;
            answer.push_back(i);
            choose(cnt + 1, i);
            answer.pop_back();
            visted[i] = false;
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    choose(0, 0);
    return 0;
}