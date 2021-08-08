#include <bits/stdc++.h>

using namespace std;

int main() {

    int t = 10;
    cout << t << "\n";

    int mod = 1e9 + 7;
    while(t--) {

        long long a = 0;
        long long b = 0;
    

        while(a < 1e3 or a > 1e4) {
            a = rand() % mod;   
        }

        while(b < 1e4 + 1 or b > 1e4 + 500) {
            b = rand() % mod;   
        }

        int da = rand() % 10 + 1;
        int db = rand() % 10 + 1;
        if(da == 10) da--;
        if(db == 10) db--;

        string aa = to_string(da) + "";
        string bb = to_string(db) + "";

        while((int)aa.size() < a) {
            aa += to_string(rand() % 10);
        }

        while((int)bb.size() < b) {
            bb += to_string(rand() % 10);
        }
        
        cout << aa.size() << " " << aa << "\n";
        cout << bb.size() << " " << bb << "\n";
    }
    return 0;
}

