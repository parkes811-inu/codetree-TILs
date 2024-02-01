#include <iostream>
#include <vector>

using namespace std;

// → ↗ ↑ ↖ ← ↙ ↓ ↘ 순서
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int map[16][16];
int n, m;

vector<int> d;      // d는 이동방향
vector<int> p;      // p는 이동칸수

vector<pair<int, int>> livro;

void move(int year) {

    for(int i = 0; i < livro.size(); i++) {
        int nx = 0, ny = 0;
        for(int j = 0; j < p[year]; j++) {
            nx = nx + dx[d[year]] % n;
            ny = ny + dy[d[year]] % n;
        }
        livro[i].first = (livro[i].first + nx) % n;
        livro[i].second = (livro[i].second + ny) % n;
    }

    for(int i = 0; i < livro.size(); i++) {
        map[livro[i].first][livro[i].second]++;
    }

    int ldx[4] = {-1, 1, -1, 1};
    int ldy[4] = {-1, 1, 1, -1};

    for(int i = 0; i < livro.size(); i++) {
        int nx = 0, ny = 0;
        int count = 0;

        for(int j = 0; j < 4; j++) {
             nx = livro[i].first + ldx[j];
             ny = livro[i].second + ldy[j];
             
             if(map[nx][ny] > 0) {
               count++; 
             }
        }

        map[livro[i].first][livro[i].second] = 
        map[livro[i].first][livro[i].second] + count;

    }
}

void removeLivro(void) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(map[i][j] >= 2) {
                map[i][j] = map[i][j] - 2;

                for(int k = 0; k < livro.size(); k++) {
                    if(i == livro[k].first && j == livro[k].second) {
                        map[i][j] = map[i][j] + 2;
                    }
                }
                livro.push_back({i, j});
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int x, y;

        cin >> x >> y;

        // dx, dy 배열 인덱스가 0부터 시작해서 -1
        d.push_back(x - 1);
        p.push_back(y);
    }

    for(int i = n - 2; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            livro.push_back({i, j});
        }
    }
    
    for(int i = 0; i < m; i++) {
        move(i);
        removeLivro();
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum = sum + map[i][j];
        }
    }

    cout << sum;
    
    return 0;
}