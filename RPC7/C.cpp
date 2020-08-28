#include <bits/stdc++.h>

using namespace std;

int dx[1010];
int dy[1010];
int dz[1010];
int main(){

    string x,y;
    cin >> x >> y;
    
    for (int i = 0; i < (int)x.size(); ++i)
        dx[i] = x[i] - 'A';
    for (int i = 0; i < (int)y.size(); ++i)
        dy[i] = y[i] - 'A';
    
    
    for (int i = 0; i < (int)y.size(); ++i)
        dz[i] = (dx[i] - dy[i] + 26) % 26;

    int p = 0;
    for (int i = y.size(); i < (int)x.size(); ++i){
        dz[i] = (dx[i] - dz[p++] + 26) % 26;
    }
    
    for (int i = 0; i < (int)x.size(); ++i)
        cout << (char)(dz[i] + 'A');
    cout << "\n";
    return 0;
}

