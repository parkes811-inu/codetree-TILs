#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[22][22];

// (x, y)에서 시작하는 최대 양수 직사각형의 크기를 반환하는 함수
int findMaxPositiveRectangle(int x, int y) {
    int maxArea = 0;
    for (int i = x; i < n; i++) {
        for (int j = y; j < m; j++) {
            bool allPositive = true;
            // 현재 탐색하는 직사각형 내부에 음수가 있는지 확인
            for (int k = x; k <= i; k++) {
                for (int l = y; l <= j; l++) {
                    if (map[k][l] <= 0) {
                        allPositive = false;
                        break;
                    }
                }
            }
            // 모두 양수라면 최대 크기 갱신
            if (allPositive) {
                maxArea = max(maxArea, (i - x + 1) * (j - y + 1));
            }
        }
    }
    return maxArea;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int answer = -1;
    // 모든 위치에서 최대 양수 직사각형의 크기를 찾음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int area = findMaxPositiveRectangle(i, j);
            answer = max(answer, area);
        }
    }

    cout << (answer > 0 ? answer : -1) << endl;
    return 0;
}