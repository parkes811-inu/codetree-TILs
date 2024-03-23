#include <iostream>
using namespace std;

int n;
int answer = 0;

// 아름다운 수인지 판별하는 함수
bool isBeautiful(const string& num) {
    int length = num.length();
    int i = 0;
    while (i < length) {
        char digit = num[i];
        int count = digit - '0'; // 현재 숫자가 나타나야 하는 횟수

        // 실제로 나타나는 횟수가 조건과 일치하는지 확인
        for (int j = 0; j < count; ++j) {
            if (i + j >= length || num[i + j] != digit) {
                return false;
            }
        }

        i += count; // 다음 숫자로 넘어감
    }
    return true;
}

// 조합을 생성하는 함수
void generate(string current, int length) {
    if (length == n) {
        if (isBeautiful(current)) {
            answer++;
        }
        return;
    }

    for (int i = 1; i <= 4; ++i) {
        generate(current + char(i + '0'), length + 1);
    }
}

int main() {
    cin >> n;
    generate("", 0);
    cout << answer << endl;
    return 0;
}