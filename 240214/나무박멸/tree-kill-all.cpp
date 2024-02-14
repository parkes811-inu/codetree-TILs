#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, m, k, c;
int map[21][21];


int dx[4] = {-1,  0, 1, 0};
int dy[4] = { 0, -1, 0, 1};


// 2번 번식을 동시에 하기 위해 
// map과 같은 크기의 배열 선언
int breedTree[21][21];

// 3번 제초제의 시간을 가지고 있어야 하기 때문에
// map과 같은 크기의 배열 선언
int herb[21][21];
int answer;


// 1-1. 상, 하, 좌, 우 4방향에 나무를 검사
int cntTree(int x, int y) {
    int cnt = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n || map[x][y] == -1) {
            continue;
        }

        if(map[nx][ny] > 0 && map[x][y] != 0) {
            cnt++;
        }
    }

    return cnt;
}   

// 1. 인접한 나무의 개수 만큼 나무 크기 증가
void GrowTree() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = cntTree(i, j);
            if(cnt > 0) {
                map[i][j] = map[i][j] + cnt;
            }
        }
    }
}


// 2. 기존에 있던 나무들은 인접한 4개의 칸 중 벽, 다른 나무, 제초제가 모두 없는 칸에 번식
void breeding() {
    
    // 동시에 반영해야 하기 때문에 같은 크기의 배열을 만들어준다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            breedTree[i][j] = 0;;
        }
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            // map[][]이 0보다 작으면 원래 비어있던 공간이거나, 벽이다.
            if(map[i][j] <= 0) {
                continue;
            }

            int cnt = 0;
            // 4 방향 검사해서 비어있는 공간을 센다.
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx >= n || ny >= n || nx < 0 || ny < 0 || map[nx][ny] < 0) {
                    continue;
                }

                if(herb[nx][ny] > 0) {
                    continue;
                }

                if(map[nx][ny] == 0) {
                    cnt++;
                }
            }

            // 4방향 검사해서 얻은 cnt만큼 번식 진행
            for(int m = 0; m < 4; m++) {
                int nx = i + dx[m];
                int ny = j + dy[m];

                if(nx > n || ny > n || nx < 0 || ny < 0) {
                    continue;
                }

                if(herb[nx][ny] > 0) {
                    continue;
                }
                
                if(map[nx][ny] == 0) {
                    breedTree[nx][ny] = breedTree[nx][ny] + map[i][j] / cnt;
                }

            }

        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            map[i][j] = map[i][j] + breedTree[i][j];
        }
    }
}

// 3. herbicide 제초제의 경우 K의 범위 만큼 대각선으로 퍼짐
// 벽이 있는 경우 가로막혀서ㅓ 전파되지 않는다.
void herbicide() {
    // 나무의 수가 동일한 칸이 있는 경우를 대비해
    // dx, dy 순서를 행이 작은 순서, 열이 작은 순서로
    int dx[4] = {-1,  1, 1, -1};
    int dy[4] = {-1, -1, 1,  1};

    int maxDel = 0;
    pair<int, int> dir = {0, 0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            // map이 0보다 작으면 벽이거나, 제초제가 뿌릴 필요가 없다.
            if(map[i][j] <= 0) {
                continue;
            }

            int cnt = map[i][j];

            // 4방향 검사를 하는데, 제초제 확산 범위 k 만큼 간다.
            for(int d = 0; d < 4; d++) {
                int nx = i;
                int ny = j;
                
                // 방향 별 k 범위 만큼 가보고, 갈 수 없는 경우 break;
                for(int m = 0; m < k; m++) {
                    nx = nx + dx[d];
                    ny = ny + dy[d];

                    if(nx >= n || ny >= n || nx < 0 || ny < 0 || map[nx][ny] <= 0) {
                        break;
                    }
                    cnt = cnt + map[nx][ny];
                }
            }

            if(maxDel < cnt) {
                maxDel = cnt;
                dir.first = i;
                dir.second = j;
            }
        }
    }

    answer = answer + maxDel;

    if(map[dir.first][dir.second] > 0) {
        map[dir.first][dir.second] = 0;
        herb[dir.first][dir.second] = c;

        for(int i = 0; i < 4; i++) {
            int nx = dir.first;
            int ny = dir.second;

            for(int j = 0; j < k; j++) {
                nx = nx + dx[i];
                ny = ny + dy[i];
                
                if(nx >= n || ny >= n || nx < 0 || ny < 0 || map[nx][ny] < 0) {
                    break;  
                }

                if(map[nx][ny] == 0) {
                    herb[nx][ny] = c;
                    break;
                }

                map[nx][ny] = 0;
                herb[nx][ny] = c;
            }
        }
    }

}

// 제초제의 기간을 1년 감소 
void DelHerb() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(herb[i][j] > 0) {
                herb[i][j] = herb[i][j] - 1;
            }
        }
    }
}

int main() {

    cin >> n >> m >> k >> c;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int start = 0; start < m; start++) {
        GrowTree();
        breeding();
        DelHerb();
        herbicide();
    }
    cout << answer;

    return 0;
}