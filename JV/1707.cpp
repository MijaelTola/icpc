#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; 

    while(cin >> n) {
        memset(v,-1,sizeof v);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            v[x] = i;
        }

        int ans=  0;
        vector<pair<int,int> > b;
        for (int i = 0; i < 1010; ++i) {
            if(v[i] != -1) {
                b.push_back({v[i],i});
                ans++;
            }
        }

        sort(b.begin(), b.end());

        cout << ans << "\n";
        for (int i = 0; i < (int)b.size(); ++i) 
            cout << b[i].second << " ";
        cout << "\n";

    }   

    return 0;
}
