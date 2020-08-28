#include <bits/stdc++.h>

using namespace std;

int v[110];
int main(){
        
    for (int i = 0; i < 50; ++i) {
        int n = rand() % 50 + 1;
        cout << n << "\n";
        for (int j = 0; j < n; ++j) {
           v[j] = rand() % 1000 + 1; 
           cout << v[j] << " ";
        }
        cout << "\n";
        for (int j = 0; j < n; ++j) {
            int r = 0;
            while(r < v[j]) r = rand()% 1000 + 1;
            cout << r << " ";
        }
        cout << "\n";
    }
    return 0;
}

