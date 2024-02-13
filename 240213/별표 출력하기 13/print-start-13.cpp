#include <iostream>
using namespace std;

int main() {
    
    int n; cin >> n;
    int q = 0;
    int plus = 1;
    int minus = n;

    if (n == 1)
    {
        cout << "*" << endl << "*";
    }
    else
    {
        // 맨위
        for (int i = 0; i < n; i++)
        {
            cout << "* ";
        }
        cout << endl;

        // 중간과 끝
        while (q != n)
        {
            for (int j = 0; j < plus; j++)
            {
                cout << "* ";
            }
            plus++;
            cout << endl;

            for (int j = minus - 1; j > 0; j--)
            {
                cout << "* ";
            }
            minus--;
            cout << endl;

            q++;
        }
    }

    return 0;
}