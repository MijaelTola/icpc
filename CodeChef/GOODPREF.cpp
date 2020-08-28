#include <bits/stdc++.h>

using namespace std;

long long a[1010];
long long b[1010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; int n;
        cin >> s >> n;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for (int i = 0; i < (int)s.size(); ++i) 
            if(s[i] == 'a') a[i] = 1;
            else b[i] = 1;

        for (int i = 1; i < (int)s.size(); ++i) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
        }
        
        long long ans = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            long long canA = a[(int)s.size() - 1] * (n - 1) + a[i];
            long long canB = b[(int)s.size() - 1] * (n - 1) + b[i];
            if(canB >= canA) {
                if(a[i] > b[i]) ans++;
                continue;
            }
            long long da = 0;
            long long db = n;
            while(da <= db) {
                long long mid = da + (db - da) / 2;
                long long curA = a[s.size() - 1] * mid + a[i];
                long long curB = b[s.size() - 1] * mid + b[i];
                if(curB >= curA) da = mid + 1;
                else db = mid - 1;
            }
            ans += (long long)(n - da);
        }
        cout << ans << "\n";
    }   
    return 0;
}

