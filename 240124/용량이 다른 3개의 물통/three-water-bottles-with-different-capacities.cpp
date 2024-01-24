#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> water(3);
    vector<int> _size(3);

    int cnt = 0;
    int flag = 0;

    for(int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        if( a == 1 && b == 1) {
            cnt ++;
        }

        if(a == b) {
            flag++;
        }
        _size[i] = a;
        water[i] = b;
    }

    if(cnt == 3) {
        cout << 1 << '\n' << 1 << '\n' << 1;
        return 0;
    }
    
    if(flag == 3) {
        for(int i = 0; i < 3; i++) {
            cout << water[i] << '\n';
        }
        return 0;
    }

    for(int i = 0; i < 100; i++) {
        
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