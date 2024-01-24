#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;

char dir;
int speed;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int map[101][101];

pair<int, int> person;

int main(void) {

	cin >> n;

	person.first = 0;
	person.second = 0;

	for (int i = 0; i < n; i++) {
		
		cin >> dir >> speed;

		if(dir == 'W') {
            person.first = person.first + (dx[0] * speed); 
            person.second = person.second + (dy[0] * speed);
            //cout << person.first << ' ' << person.second << '\n';

        }
        else if(dir == 'S') {
            person.first = person.first + (dx[1] * speed); 
            person.second = person.second + (dy[1] * speed);
            //cout << person.first << ' ' << person.second << '\n';
        }
        else if(dir == 'N') {
            person.first = person.first + (dx[2] * speed); 
            person.second = person.second + (dy[2] * speed);
            //cout << person.first << ' ' << person.second << '\n';
        }
        else if(dir == 'E') {
            person.first = person.first + (dx[3] * speed); 
            person.second = person.second + (dy[3] * speed);
            //cout << person.first << ' ' << person.second << '\n';
        }
	}

    cout << person.first << ' ' << person.second;
	return 0;
}