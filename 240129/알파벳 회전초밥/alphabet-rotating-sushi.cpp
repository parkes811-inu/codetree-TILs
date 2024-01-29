#include <iostream>
#include <string>

using namespace std;

int main() {
    string lst;
    string word;
    cin >> lst;
    cin >> word;

    int bf = 0;
    int res = 1;

    for (int i = 0; i < word.size(); i++) {
        size_t num = lst.find(word[i]);
        if (bf >= num) {
            res += 1;
        }
        bf = num;
    }

    cout << res << endl;

    return 0;
}