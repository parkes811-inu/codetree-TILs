#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n), final_state(n), initial_state(n);
    vector<int> position(n);

    // 수열 A를 입력받아 위치 매핑을 생성합니다.
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
        position[sequence[i] - 1] = i;
    }

    // 최종 카드 상태를 입력받습니다.
    for (int i = 0; i < n; i++) {
        cin >> final_state[i];
    }

    // 카드를 섞는 과정을 3번 역으로 수행합니다.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            initial_state[position[j]] = final_state[j];
        }
        final_state = initial_state;
    }

    // 초기 상태를 출력합니다.
    for (int i = 0; i < n; i++) {
        cout << initial_state[i] << '\n';
    }

    return 0;
}