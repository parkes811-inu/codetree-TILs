#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

   for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i + 1; j--)
            cout << " ";
        for (int k = 0; k < i + 1; k++)
            cout << "*" << " ";
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int k = n; k > i; k--)
            cout << "*" << " ";
        cout << endl;
    }
    return 0;
}