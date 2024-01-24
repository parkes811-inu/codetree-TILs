#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int s, t, b;

    cin >> n;
    
    vector<int> time (1000, 0);
    for(int i = 0; i < n; i++) {
        cin >> s >> t >> b;

        for(int j = s; j < t; j++) {
            time[j] = time[j] + b;
        }
    }

    //sort(time.begin(), time.end());

    //cout << time[time.size() - 1];
    int answer = *max_element(time.begin(), time.end());
    cout << answer;
    return 0;
}