#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[102];
int temp[102];
vector<int> answer;
vector<int> bombList;
int count;

void delBomb() {
    
    int idx = 1;
    for(int i = 0; i < bombList.size(); i++) {
        int del = bombList[i];
        for(int j = 1; j <= n; j++) {
            if(arr[j] != del) {
                temp[idx] = arr[j];
                idx = idx + 1;
            }
        }
    }

    for(int i = 0; i < bombList.size(); i++) {
        bombList.pop_back();
    }

    for(int i = 1; i <= idx; i++) {
        arr[i] = temp[i];
    }

}

void checkBomb() {
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i + 1]) {
            cnt++;
        }
        else {
            cnt = 1;
        }

        if(cnt >= m) {
            bool flag = true;
            for(int j = 0; j < bombList.size(); j++) {
                if(bombList[j] == arr[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag != false) {
                bombList.push_back(arr[i]);    
            }
        }
    }
    for(int i = 0; i < n - bombList.size(); i++) {
        cout << bombList[i] << ' ';
    }
    count = bombList.size();
    //cout << count;
}

void initBomb() {
    for(int i = 0; i < 102; i++) {
        temp[i] = 0;
    }
}

void print() {
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

   // while(1) {
        checkBomb();
        cout << "checkBomob after-------------\n";
        print();
     //   if(bombList.empty() == true) {
         //   break;
       // }
        delBomb();
        //initBomb();

        cout << "delBomob after-------------\n";
       print();
  //  }
    cout << "---------------last answer \n";
    print();

    return 0;
}