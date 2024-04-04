#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 41
#define MAX_L 41
#define TRAP 1
#define WALL 2
using namespace std;

int L, N;
int grid[MAX_N][MAX_N];

int r[MAX_N], c[MAX_N], h[MAX_N], w[MAX_N], k[MAX_N];
int bef_k[MAX_N];
int nr[MAX_N], nc[MAX_N];
int dmg[MAX_N];
bool is_moved[MAX_N];

int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };


bool TryMove(int id, int dir) {
    memset(is_moved, 0, sizeof(is_moved));
    memset(dmg, 0, sizeof(dmg));

    queue<int> q;
    q.push(id);
    is_moved[id] = true;
    while (!q.empty()) {
        int cid = q.front(); q.pop();

        //sy sx ~ ey ex
        int sy = r[cid] + dy[dir], sx = c[cid] + dx[dir];
        int ey = sy + h[cid] - 1, ex = sx + w[cid] - 1;
        nr[cid] = sy, nc[cid] = sx;

        //모두 범위 내에 있어야하고 
        if (sy < 1 || sx < 1 || L < ey || L < ex) 
            return false;

        //내부에 벽이 있으면 안된다.
        //내부 벽 찾으며 동시에 대미지 계산
        for (int i = sy; i <= ey; i++) {
            for (int j = sx; j <= ex; j++) {
                if (grid[i][j] == WALL) return false;
                if (grid[i][j] == TRAP) dmg[cid]++;
            }
        }
        //id 전체 돌며 사각형 내부에 id 있으면 넣어 
        //안움직인거라면
        for (int i = 1; i <= N; i++) {
            if (is_moved[i] || k[i] <= 0) continue;
            if (r[i] + h[i] - 1 < sy || ey < r[i]) continue;
            if (c[i] + w[i] - 1 < sx || ex < c[i]) continue;
            q.push(i);
            is_moved[i] = true;
        }
    }
    dmg[id] = 0;
    return true;
}


void Move(int id, int dir) {
    if (k[id] <= 0) return;

    if (TryMove(id, dir)) {
        for (int i = 1; i <= N; i++) {
            if (is_moved[i]) {
                r[i] = nr[i], c[i] = nc[i];
                k[i] -= dmg[i];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int Q;
    cin >> L >> N >> Q;
    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= L; j++)
            cin >> grid[i][j];   
            
    for (int i = 1; i <= N; i++) {
        cin >> r[i] >> c[i] >> h[i] >> w[i] >> k[i];
        bef_k[i] = k[i];
    }

    while (Q--) {
        int id, dir;
        cin >> id >> dir;
        Move(id, dir);
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        if (k[i] > 0) {
            ans += bef_k[i] - k[i];
        }
    }

    cout << ans;
    return 0;
}