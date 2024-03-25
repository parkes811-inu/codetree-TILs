#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x, y;
int blockCounter = 0;
int counter = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector <int> vec;

int arr[101][101];
bool visited[101][101];

bool inRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(int x, int y) {
    int curr = arr[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inRange(nx, ny) && arr[nx][ny] == curr && !visited[nx][ny]) {
            counter++;
            visited[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;

    if (n == 1) {
        cout << 0 << " " << 1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                counter = 0;
                dfs(i,j);
                if (counter >= 2)
                    vec.push_back(counter);
                if (counter >= 4)
                    blockCounter++;
            }
        }
    }
    sort(vec.rbegin(), vec.rend());
    cout << blockCounter << " " << vec[0];
    return 0;
}