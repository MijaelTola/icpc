#include <bits/stdc++.h>

using namespace std;

char c[100010][25];
int main(){
    
    int n,k; 
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) 
            cin >>  c[i][j];
    }
    for (int i = 0; i < k; ++i) {
        int c0,c1;
        c1 = c0 = 0;
        for (int j = 0; j < n; ++j) {
            if(c[j][i] == '1') c1++;
            else c0++;
        }

        if(c1 >= c0) cout << "0";
        else cout << "1";
    }
    cout << "\n";
    return 0;
}

