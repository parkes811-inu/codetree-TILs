#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> water(3);
    vector<int> _size(3);

    for(int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;

        _size[i] = a;
        water[i] = b;
    }

    for(int i = 0; i < 4; i++) {
        
        int temp = water[i % 3];
        water[(i + 1) % 3] = water[(i + 1) % 3] + water[i % 3];

        if(water[(i + 1) % 3] > _size[(i + 1) % 3]) {
            water[i % 3] = water[i % 3] - _size[(i + 1) % 3];
            water[(i + 1) % 3] = _size[(i + 1) % 3];
        }
        else {
            water[i % 3] = water[i % 3] - temp;
        }
    } 

    for(int i = 0; i < 3; i++) {
        cout << water[i] << '\n';
    }
    return 0;
}