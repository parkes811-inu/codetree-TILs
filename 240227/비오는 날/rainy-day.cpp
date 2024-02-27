#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<tuple<string, string, string>> weather;

bool cmp(tuple<string, string, string> a, tuple<string, string, string> b) {
    if(get<0>(a) < get<0>(b)) {
        return true;
    }
    return false;
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        weather.push_back(make_tuple(a, b, c));
    }
    sort(weather.begin(), weather.end(), cmp);

    for(int i = 0; i < n; i++) {
        if(get<2>(weather[i]) == "Rain") {
            cout << get<0>(weather[i]) << ' ';
            cout << get<1>(weather[i]) << ' ';
            cout << get<2>(weather[i]) << '\n';
            return 0;
        }
    }
    return 0;
}