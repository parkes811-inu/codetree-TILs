#include <iostream>
#include <vector>

using namespace std;

int n, q;
int map[1025][1025];

vector<int> x1;
vector<int> x2;
vector<int> y1;
vector<int> y2;
vector<int> answer;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    
    
    for(int i = 0; i < q; i++) {
        int _x1, _x2, _y1, _y2;

        cin >> _x1 >> _y1 >> _x2 >> _y2;

        x1.push_back(_x1-1);
        x2.push_back(_x2-1);
        y1.push_back(_y1-1);
        y2.push_back(_y2-1);
    }
    
    for(int k = 0; k < q; k++) {
        int sum = 0;
        for(int i = x1[k]; i <= x2[k]; i++) {
            for(int j = y1[k]; j <= y2[k]; j++) {
                sum = sum + map[i][j];
            }
        }
        answer.push_back(sum);
    }

    for(int i = 0; i < q; i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}