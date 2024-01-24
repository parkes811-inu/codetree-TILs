#include <iostream>
#include <vector>

using namespace std;

void transferWater(int& from, int& to, int to_max) {
    int transferable = min(from, to_max - to);
    from -= transferable;
    to += transferable;
}

int main() {
    vector<int> capacity(3), water(3);

    for(int i = 0; i < 3; i++) {
        cin >> capacity[i] >> water[i];
    }

    for(int i = 0; i < 100; i++) {
        transferWater(water[0], water[1], capacity[1]);
        transferWater(water[1], water[2], capacity[2]);
        transferWater(water[2], water[0], capacity[0]);
    }

    for(int i = 0; i < 3; i++) {
        cout << water[i] << '\n';
    }

    return 0;
}