#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int n;
long long v[100010];

int f(int pos,long long last){
    if(pos == n) return 0;
    int ans = -1;
    if(v[pos] == last) ans = max(ans,f(pos+1,last)+1);
    return max(ans,max(f(pos+1,v[pos]),f(pos+1,last)));
}
map<long long,int> ans;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i){
        long long x; cin >> x;
        ans[x]++;
    }
    int c = -1;
    for (pair<long long,int>i: ans) c = max(c,i.second);
    //cout << c << endl;
    if(c > n/2) cout << 1 << "\n";
    else cout << 0 <<"\n";
   /* for (int  = 0; i < n; ++i) cin >>  v[i];
    sort(v,v+n);
    for (int i = 0; i < n; ++i){
        
    }*/
 /*   int ans = f(0,v[0]);
    if(ans > n/2) cout << 1 << endl;
    else cout << 0 << endl;*/
    return 0;
}
