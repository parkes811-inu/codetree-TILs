#include <iostream>

using namespace std;
int r, c, cnt;
char map[17][17];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
   int i, j, l, k;
    for(i=1; i<r; i++)
    {
        for(j=1; j<c; j++)
        {
            for(k=i+1; k<r-1; k++)
            {
                for(l=j+1; l<c-1; l++)
                {
                    if(map[0][0]!=map[i][j] && map[i][j]!=map[k][l] && map[k][l]!=map[r-1][c-1])
                    {
                        cnt++;
                    }
  
                }
            }

        }
    }
    cout << cnt;
    return 0;
}