#include <iostream>
#include <algorithm>
#include <string>
#define DIRNUM 8

using namespace std;

string arr[100];
int n, m;
int dx[DIRNUM] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[DIRNUM] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] != 'L') continue;

            for(int k=0; k<DIRNUM; k++){
                
                int nx1 = i + dx[k];
                int ny1 = j + dy[k];
                int nx2 = nx1 + dx[k];
                int ny2 = ny1 + dy[k];
                
                if(!InRange(nx1, ny1) || !InRange(nx2, ny2)){
                    continue;
                }
                //cout << i << " " << j << " " << nx1 << " " << ny1 << " " << nx2 << " " << ny2 << endl;
                if(arr[nx1][ny1] == 'E' && arr[nx2][ny2] == 'E'){
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}