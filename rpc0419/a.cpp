#include <bits/stdc++.h>

using namespace std;

int n,x;
int v[100010];
int main() {
    
    cin >> n >> x;
    for (int i = 0; i <n ; ++i) 
        cin >> v[i];
    
    if(n == 1) {
        return cout << 1 << "\n",0;
    }   
    sort(v, v + n);
    
    int last = 0;
    int pos = 0;

    while(pos < n) {
        if(v[pos] + last > x) break;
        last = v[pos];
        pos++;
    }
    cout << max(1,pos) << "\n";
    return 0;
}

