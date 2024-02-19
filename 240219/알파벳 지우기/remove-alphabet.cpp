#include <iostream>

using namespace std;
string a, b, a1, b1;
int sum;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= '0' && a[i] <= '9')  {
            a1 = a1 + a[i];
        }
    }

    for(int i = 0; i < b.size(); i++) {
        if(b[i] >= '0' && b[i] <= '9')  {
            b1 = b1 + b[i];
        }
    }
  
    sum = sum + stoi(a1) + stoi(b1);
    cout << sum;
    return 0;
}