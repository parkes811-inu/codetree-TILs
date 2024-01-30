#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> numbers = {a, b, c, a * b, a * c, b * c, a * b * c};

    // 홀수를 먼저, 그 다음 짝수를 고려하고, 둘 다 같으면 큰 숫자를 우선하는 정렬
    sort(numbers.begin(), numbers.end(), [](int x, int y) {
        if ((x % 2 != 0) && (y % 2 == 0)) return true; // x가 홀수이고 y가 짝수면 x 우선
        if ((x % 2 == 0) && (y % 2 != 0)) return false; // x가 짝수이고 y가 홀수면 y 우선
        return x > y; // 같은 홀수나 짝수일 경우 큰 숫자 우선
    });

    cout << numbers.front() << endl; // 가장 높은 우선순위를 가진 수 출력

    return 0;
}