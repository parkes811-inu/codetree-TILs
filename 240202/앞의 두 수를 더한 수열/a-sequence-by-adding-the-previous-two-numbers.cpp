#include <iostream>

using namespace std;

int arr[21];
int n;
int answer = 0;

void findN(int i, int n) {

    if(i == n) {
        cout << answer;
        return;
    }
    arr[i] = arr[i - 2] + arr[i - 1];
    answer = arr[i];
    findN(i+1, n);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    arr[0] = 0;
    arr[1] = 1;

    findN(2, n+1);

    return 0;
}