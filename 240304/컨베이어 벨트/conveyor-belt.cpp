#include <iostream>

using namespace std;
int belt[2][201];
int n, t;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> belt[i][j];
        }
    }

    for(int i = 0; i < t; i++) {

        int first = belt[1][n - 1];
        int last = belt[0][n - 1];

        for(int j = n - 1; j > 0; j--) {
            belt[0][j] = belt[0][j - 1]; 
        }
        belt[0][0] = first;

        for(int k = n - 1; k > 0; k--) {
            belt[1][k] = belt[1][k - 1];
        }
        belt[1][0] = last;
    }
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cout << belt[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}