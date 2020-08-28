#include <bits/stdc++.h>

using namespace std;

pair<int,int> v[1000010];
int a[1000010];
long long b[1000010];
int main(){
    
    int n,t; 
    cin >> n >> t;

    int id = -1;
    int mx = 0;
    for (int i = 0; i < n; ++i){
        cin >> v[i].first;
        b[i] = v[i].first;
        a[i] = v[i].first;
        v[i].second = i;
        if(i) b[i] += b[i-1];
  
    }
    
    sort(v,v + n);
    reverse(v,v + n);

    long long ans = 0;
    for (int i = 0; i < n; ++i){
        int pos = v[i].second;
        long long cur = b[pos];
        t -= pos;
        int id = pos + 1;
        if(pos and a[pos - 1] > a[pos + 1]) id = pos - 1;
        int tr = t / 2;
        cur += tr * a[pos]  + tr * a[id];
        if(t % 2) cur += a[id];
        ans = max(ans,cur);
    }
    cout << ans << "\n";
    return 0;
}

