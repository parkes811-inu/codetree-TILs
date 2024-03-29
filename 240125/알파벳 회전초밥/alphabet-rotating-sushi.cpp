#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a;
string b;
vector<pair<char, int>> answer;
string result = "";
int count = 1;

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++) {
        answer.push_back(make_pair(a[i], i));
    }
    int i = 0; int j = 0;

    while(1) {
        if(j == b.size()) {
            cout << count;
            break;
        }

        if(answer[i].first == b[j]) {
            j++;
        }

        i++;
        if(i == 25) {
            count++;
            i = 0;
        }
    }   
    return 0;
}