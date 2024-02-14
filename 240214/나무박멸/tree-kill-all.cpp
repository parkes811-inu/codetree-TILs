#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 22
#define DIR 4

using namespace std;

int n, m, k, c;

int tree[MAX][MAX];
int addTree[MAX][MAX];
int herb[MAX][MAX];

int dx[DIR] = { -1, 0, 1, 0 };
int dy[DIR] = { 0, 1, 0, -1 };

int answer;

bool OutOfRange(int x, int y) {
	if (x > 0 && y > 0 && x <= n && y <= n) {
		return true;
	}
	return false;
}

void init() {

	cin >> n >> m >> k >> c;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tree[i][j];
		}
	}
}

void print() {

	cout << '\n';
	cout << "-------------------------\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << tree[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "-------------------------\n";
}

// 1. 인접한 네 개의 칸 중 나무가 있는 칸의 수만큼 나무가 성장합니다. 성장은 모든 나무에게 동시에 일어납니다.
// - 모든 나무에게 동시에 일어나지만, 나무의 크기에 영향을 받는 것이 아니기 때문에
// - 따로 배열을 만들어 진행할 필요가 없다. -> 단순 네 개의 칸 중 나무가 있는지 없는지 여부에 따라 크기가 증가
void growTree() {
	
	// 맵 전체에 대해 검사
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 나무가 있는 곳을 세기 위한 변수
			int cnt = 0;
			
			// 나무가 없는 곳은 생략하면 되기 때문에continue; 사용
			if(tree[i][j] == 0) {
				continue;
			}
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (OutOfRange(nx, ny) == false || tree[nx][ny] <= 0) {
					continue;
				}
				
				if (tree[nx][ny] > 0) {
					cnt++;
				}
			}
			if (tree[i][j] > 0) {
				tree[i][j] = tree[i][j] + cnt;
			}
		}
	}
}

// 2. 기존에 있던 나무들과 인접한 4개의 칸중 벽, 다른 나무, 제초제가 없는 칸에 번식 진행
// - 현재 칸 / 번식이 가능한 카의 개수 (나머지는 버림)
// - 번식의 과정은 모든 나무에서 동시에 일어난다 
// -> 나무의 크기가 한 번에 바뀌어야 하기 때문에 번식할 개수를 담는 배열을 하나 만듬.
void breeding() {

	// 나무의 크기를 한 번에 바꾸기 위한 임시 배열
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			addTree[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cnt = 0;

			// 현재의 칸에 나무가 있어야 번식이 가능하기 때문에 0 보다 아래는 건너뜀
			if (tree[i][j] <= 0) {
				continue;
			}

			// 4방향 검사 후 cnt증가
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (OutOfRange(nx, ny) == false || tree[nx][ny] != 0) {
					continue;
				}

				if (tree[nx][ny] == 0) {
					cnt++;
				}
			}

			// addTree라는 임시 배열에 번식될 값을 넣어줌
			for (int m = 0; m < 4; m++) {
				int nx = i + dx[m];
				int ny = j + dy[m];
				
				if (OutOfRange(nx, ny) == false || tree[nx][ny] != 0) {
					continue;
				}

				if (tree[nx][ny] == 0) {
					addTree[nx][ny] = addTree[nx][ny] + tree[i][j] / cnt;
				}
			}

		}
	}

	// 임시 저장되었던 배열들에 값을 tree 배열에 더해준다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (addTree[i][j] > 0) {
				tree[i][j] = tree[i][j] + addTree[i][j];
			}
		}
	}
}
/*
* 각 칸 중 제초제를 뿌렸을 때 나무가 가장 많이 박멸되는 칸에 제초제를 뿌립니다. 
나무가 없는 칸에 제초제를 뿌리면 박멸되는 나무가 전혀 없는 상태로 끝이 나지만, 
나무가 있는 칸에 제초제를 뿌리게 되면 4개의 대각선 방향으로 k칸만큼 전파되게 됩니다. 
단 전파되는 도중 벽이 있거나 나무가 아얘 없는 칸이 있는 경우, 그 칸 까지는 제초제가 뿌려지며 
그 이후의 칸으로는 제초제가 전파되지 않습니다. 
제초제가 뿌려진 칸에는 c년만큼 제초제가 남아있다가 c+1년째가 될 때 사라지게 됩니다. 
제초제가 뿌려진 곳에 다시 제초제가 뿌려지는 경우에는 새로 뿌려진 해로부터 다시 c년동안 제초제가 유지됩니다.

*/
void herbicide() {

	int maxDel = 0;
	pair<int, int> dir = { 1, 1 };

	int dx[4] = { -1,  1, 1, -1 };
	int dy[4] = { -1, -1, 1,  1 };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			if (tree[i][j] <= 0) {
				continue;
			}

			int cnt = tree[i][j];
			for (int d = 0; d < 4; d++) {
				int nx = i;
				int ny = j;

				for (int m = 1; m <= k; m++) {
					nx = nx + dx[d];
					ny = ny + dy[d];

					if (OutOfRange(nx, ny) == false) {
						break;
					}
					if (tree[nx][ny] <= 0) {
						break;
					}
						
					cnt = cnt + tree[nx][ny];
				}
			}

			if (maxDel < cnt) {
				maxDel = cnt;
				dir.first = i;
				dir.second = j;
			}
		}
	}
	answer = answer + maxDel;

	if (tree[dir.first][dir.second] > 0) {
		tree[dir.first][dir.second] = 0;
		herb[dir.first][dir.second] = c;

		for (int d = 0; d < 4; d++) {
			int nx = dir.first;
			int ny = dir.second;

			for (int m = 1; m <= k; m++) {
				nx = nx + dx[d];
				ny = ny + dy[d];

				if (OutOfRange(nx, ny) == false || tree[nx][ny] <= 0) {
					break;
				}
				
				if (tree[nx][ny] == 0) {
					herb[nx][ny] = c;
					break;
				}
				tree[nx][ny] = 0;
				herb[nx][ny] = c;
			}
		}
	}
}

void DelHerb() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (herb[i][j] > 0) {
				herb[i][j] = herb[i][j] - 1;
			}
		}
	}
}

int main(void) {


	init();
	for (int i = 1; i <= m; i++) {
		growTree();
		breeding();
		DelHerb();
		herbicide();
	}
	cout << answer;
	return 0;
}