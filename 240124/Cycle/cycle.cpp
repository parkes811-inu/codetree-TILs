#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> sequence;
    unordered_map<int, int> position;
    int current = n;
    while (true) {
        current = (current * n) % p;
        // 이미 등장했던 숫자가 등장하면 사이클의 크기를 출력
        if (position.find(current) != position.end()) {
            cout << sequence.size() - position[current] << endl;
            break;
        }
        // 숫자와 그 위치를 저장
        position[current] = sequence.size();
        sequence.push_back(current);
    }
    return 0;
}