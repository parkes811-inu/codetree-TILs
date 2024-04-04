#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Knight {
    int r, c, h, w, k; // 위치(r, c), 크기(h, w), 체력(k)
    bool isAlive = true; // 기사가 살아있는지 여부
};

int L, N, Q;
vector<vector<int>> map; // 체스판 정보 (0: 빈칸, 1: 함정, 2: 벽)
vector<Knight> knights; // 모든 기사들의 정보

int answer;

int dx[4] = {-1, 0, 1, 0}; // 상, 우, 하, 좌 방향 벡터
int dy[4] = {0, 1, 0, -1};

// 지정된 위치가 체스판 범위 내에 있는지 확인
bool InRange(int x, int y) {
    return x >= 1 && x <= L && y >= 1 && y <= L;
}

// 지정된 위치에 함정이 있는지 확인
bool IsTrap(int x, int y) {
    return InRange(x, y) && map[x][y] == 1;
}

// 지정된 위치에 벽이 있는지 확인
bool IsWall(int x, int y) {
    return !InRange(x, y) || map[x][y] == 2;
}

// 해당 방향으로 이동할 때 모든 기사가 이동 가능한지 확인
bool CanMove(int dir) {
    for (const auto& knight : knights) {
        if (knight.isAlive) {
            int nx = knight.r + dx[dir];
            int ny = knight.c + dy[dir];
            // 벽이 있으면 이동 불가
            if (IsWall(nx, ny)) return false;
        }
    }
    return true;
}

// 기사 이동 처리
void MoveKnights(int dir) {
    if (!CanMove(dir)) return; // 이동할 수 없는 경우

    for (auto& knight : knights) {
        if (knight.isAlive) {
            knight.r += dx[dir];
            knight.c += dy[dir];
        }
    }
}

// 대미지 처리
void ApplyDamage() {
    int totalDamage = 0;
    for (auto& knight : knights) {
        if (knight.isAlive) {
            int damage = 0;
            // 기사가 차지하는 영역 내의 모든 함정 확인
            for (int i = 0; i < knight.h; ++i) {
                for (int j = 0; j < knight.w; ++j) {
                    if (IsTrap(knight.r + i, knight.c + j)) {
                        damage++;
                    }
                }
            }
            knight.k -= damage; // 체력 감소
            totalDamage += damage; // 총 대미지 계산
            if (knight.k <= 0) knight.isAlive = false; // 기사 사망 처리
        }
    }
    answer = answer + totalDamage;
}

int main() {
    cin >> L >> N >> Q;
    map.resize(L + 1, vector<int>(L + 1));
    knights.resize(N);

    // 체스판 정보 입력
    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= L; ++j) {
            cin >> map[i][j];
        }
    }

    // 기사 정보 입력
    for (int i = 0; i < N; ++i) {
        cin >> knights[i].r >> knights[i].c >> knights[i].h >> knights[i].w >> knights[i].k;
    }

    // 명령 처리
    for (int i = 0; i < Q; ++i) {
        int id, dir;
        cin >> id >> dir; // 기사 ID와 이동 방향
        if (knights[id-1].isAlive) { // 사라지지 않은 기사에 대해서만 처리
            MoveKnights(dir);
            ApplyDamage(); // 이동 후 대미지 처리
        }
    }
    cout << answer;
    return 0;
}