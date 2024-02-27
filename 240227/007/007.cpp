#include <iostream>
#include <tuple>

using namespace std;
tuple<string, char, int> t;

int main() {
    // 여기에 코드를 작성해주세요.
    string a;
    char b;
    int c;

    cin >> a >> b >> c;
    t = make_tuple(a, b, c);
    cout << "secret code : " << get<0>(t) << '\n';
    cout << "meeting point : " << get<1>(t) << '\n';
    cout << "time : " << get<2>(t);
    return 0;
}