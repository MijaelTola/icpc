#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        for (int i = 1; i <= n; ++i) cin >> v[i];
        queue<pair<int,int> > q;
        for (int i = 2; i <= n - 1; ++i) 
            if(v[i - 1] > v[i] and v[i] < v[i + 1]) 
                q.push(make_pair(v[i],i));
        
        
    }
    return 0;
}

