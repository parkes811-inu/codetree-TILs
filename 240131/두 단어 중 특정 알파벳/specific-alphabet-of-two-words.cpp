#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> max_count(26, 0); // 각 알파벳의 최대 등장 횟수를 저장하는 배열

    while (n--) {
        string a, b;
        cin >> a >> b;

        vector<int> count_a(26, 0), count_b(26, 0);

        // a 단어에서 각 알파벳의 등장 횟수를 센다
        for (char ch : a) {
            count_a[ch - 'a']++;
        }

        // b 단어에서 각 알파벳의 등장 횟수를 센다
        for (char ch : b) {
            count_b[ch - 'a']++;
        }

        // a와 b에서 각 알파벳의 최대 등장 횟수를 비교하여 max_count 배열을 업데이트한다
        for (int i = 0; i < 26; i++) {
            max_count[i] = max(max_count[i], max(count_a[i], count_b[i]));
        }
    }

    // 각 알파벳의 최대 등장 횟수를 출력한다
    for (int count : max_count) {
        cout << count << '\n';
    }

    return 0;
}