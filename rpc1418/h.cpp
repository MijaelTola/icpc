#include <bits/stdc++.h>

using namespace std;

int n; 
string v[40], b[40];
bool isLatin() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if(k == i) continue;
                if(v[k][j] == v[i][j]) return 0;
            }
            for (int k = 0; k < n; ++k) {
                if(k == j) continue;
                if(v[i][k] == v[i][j]) return 0;
            }
        }
    }
    return 1;
}

int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i) { 
        cin >> v[i];
        b[i] = v[i];
    }
    
    if(!isLatin()) return puts("No"),0;
    
    sort(b, b + n);

    for (int i = 0; i < n; ++i) 
        if(v[i] != b[i]) return puts("Not Reduced"),0;

    puts("Reduced");
    
    return 0;
}

