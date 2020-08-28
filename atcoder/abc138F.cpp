#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    map<int,int> a;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            if((i % j) == (i ^ j)) {
                cout << i << " " << j << "\n";
                a[i]++;
                cnt++;
            }
    }

    //for (auto x: a)
        //cout << x.second << " ";
    //cout << "\n";


    
    return 0;
}

