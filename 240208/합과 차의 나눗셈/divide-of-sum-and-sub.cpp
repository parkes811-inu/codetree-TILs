#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double a, b;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    double result = round((a+b) / (a-b) * 100);
    
    result = result / 100;
  
    cout << result;
    return 0;
}