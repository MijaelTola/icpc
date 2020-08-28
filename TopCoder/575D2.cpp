#include <bits/stdc++.h>

using namespace std;

class TheNumberGameDivTwo {
public:
	string find(int);
};

int prime[1010];
int win[1010];

string TheNumberGameDivTwo::find(int n) {

    for (int i = 1; i < 1010; ++i) 
        for (int j = i + i; j < 1010; j += i) 
            prime[j] = 1;

    for (int i = 0; i < 1010; ++i) 
        if(!prime[i]) win[i] = 1;
    
    win[1] = win[0] = 0;
    for (int i = 4; i <= n; ++i) {
        bool flag = 0;
        for (int j = 2; j < i; j++) {
            if(i % j == 0) 
                flag |= !win[i - j];
        }
        win[i] = flag;
    }
    if(win[n]) return "John";
    return "Brus";
}

int main() {
    TheNumberGameDivTwo T;
    int n;
    cin >> n;
    cout << T.find(n) << "\n";
}

