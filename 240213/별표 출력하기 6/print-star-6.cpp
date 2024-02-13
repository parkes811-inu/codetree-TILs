#include <iostream>

using namespace std;

int n;

int main ()
{
    int n;
    cin >> n;
            
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        cout << "  ";
        for (int k = (2 * n) - 1; k > 2 * i; k--)
        cout << "*" << " ";
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = n; j > i + 1; j--)
        cout << "  "; 
        for (int k = 0; k < (i * 2) + 1; k++)
        cout << "*" << " ";
        cout << endl;
    }
}