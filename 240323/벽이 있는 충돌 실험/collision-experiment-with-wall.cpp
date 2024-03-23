#include <iostream>
#include <vector>
#include <algorithm> // std::remove_if 사용

using namespace std;

// 위, 아래, 왼쪽, 오른쪽
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Marble {
    int x, y;
    char dir;
    bool removed = false; // 구슬이 제거되었는지 표시
};

vector<Marble> marbles;
int n, m;

bool InRange(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

char ReverseDir(char dir) {
    switch (dir) {
        case 'U': return 'D';
        case 'D': return 'U';
        case 'L': return 'R';
        case 'R': return 'L';
    }
    return dir; // 기본 경우
}

void MoveAndDetectCollisions() {
    // 구슬 이동
    for (auto& marble : marbles) {
        int dirIndex;
        if (marble.dir == 'U') dirIndex = 0;
        else if (marble.dir == 'D') dirIndex = 1;
        else if (marble.dir == 'L') dirIndex = 2;
        else if (marble.dir == 'R') dirIndex = 3;

        int nx = marble.x + dx[dirIndex];
        int ny = marble.y + dy[dirIndex];

        // 벽에 부딪혔을 경우
        if (!InRange(nx, ny)) {
            marble.dir = ReverseDir(marble.dir); // 방향 반전
        } else {
            marble.x = nx;
            marble.y = ny;
        }
    }

    // 충돌 검출
    for (int i = 0; i < marbles.size(); i++) {
        if (marbles[i].removed) continue; // 이미 제거된 구슬은 무시
        for (int j = i + 1; j < marbles.size(); j++) {
            if (marbles[j].removed) continue;
            if (marbles[i].x == marbles[j].x && marbles[i].y == marbles[j].y) {
                // 두 구슬이 같은 위치에 있으면 제거
                marbles[i].removed = marbles[j].removed = true;
            }
        }
    }

    // 제거된 구슬 제거
    marbles.erase(remove_if(marbles.begin(), marbles.end(), [](const Marble& marble) {
        return marble.removed; // 제거된 구슬을 벡터에서 제거
    }), marbles.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        marbles.clear();
        marbles.resize(m);

        for (int i = 0; i < m; i++) {
            cin >> marbles[i].x >> marbles[i].y >> marbles[i].dir;
            marbles[i].x--; // 0-based 인덱스 조정
            marbles[i].y--;
            marbles[i].removed = false; // 초기화
        }

        // 충분한 시간 동안 구슬 이동 시도
        for (int time = 0; time < 2*n -1; time++) {
            MoveAndDetectCollisions();
        }

        cout << marbles.size() << endl;
    }

    return 0;
}