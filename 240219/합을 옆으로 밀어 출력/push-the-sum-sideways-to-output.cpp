#include <iostream>
#include <string>
using namespace std;
int n, temp;
string sum;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num; 
        cin >> num;
        temp = temp + num;
    }
    sum = to_string(temp);
    sum = sum.substr(1, sum.size() - 1) + sum[0];
    cout << sum;
    return 0;
}