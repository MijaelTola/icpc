#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    
    int t; cin >> t;

    while(t--) {
        memset(v, 0, sizeof v);
        int n,x,s;
        cin >> n >> x >> s;
        v[x] = 1;
        for (int i = 0; i < s; ++i) {
            int a,b; cin >> a >> b;
            swap(v[a],v[b]);
        }
        int id = -1;
        for (int i = 0; i <= n; ++i) 
            if(v[i]) id = i;
        cout << id << "\n";
    }
    return 0;
}

