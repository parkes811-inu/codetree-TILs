#include <iostream>

#define MAX_N 1000
#define DIR_NUM 4

using namespace std;

int n;
char arr[MAX_N][MAX_N];

int start_num;
int x, y, move_dir;

// 주어진 숫자에 따라
// 시작 위치와 방향을 구합니다.
void Initialize(int num) {
    if(num <= n) {
        x = 0; y = num - 1; move_dir = 0;
    }
    else if(num <= 2 * n) {
        x = num - n - 1; y = n - 1; move_dir = 1;
    }
    else if(num <= 3 * n) {
        x = n - 1; y = n - (num - 2 * n); move_dir = 2;
    }
    else {
        x = n - (num - 3 * n); y = 0; move_dir = 3;
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// (x, y)에서 시작하여 next_dir 방향으로
// 이동한 이후의 위치를 구합니다.
void Move(int next_dir) {
    int dx[DIR_NUM] = {1,  0, -1, 0};
    int dy[DIR_NUM] = {0, -1,  0, 1};
    
    x += dx[next_dir];
    y += dy[next_dir];
    move_dir = next_dir;
}

int Simulate() {
    int move_num = 0;
    while(InRange(x, y)) {
        // 0 <-> 1 / 2 <-> 3
        if(arr[x][y] == '/')
            Move(move_dir ^ 1);
        // 0 <-> 3 / 1 <-> 2
        else
            Move(3 - move_dir);
        
        move_num += 1;
    }
    
    return move_num;
}

int main() {
    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    cin >> start_num;
 
    // 시작 위치와 방향을 구합니다.
    Initialize(start_num);
    // (x, y)에서 move_dir 방향으로 시작하여
    // 시뮬레이션을 진행합니다.
    int move_num = Simulate();
    
    cout << move_num;
    return 0;
}