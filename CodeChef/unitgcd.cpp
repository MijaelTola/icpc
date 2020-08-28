#include <bits/stdc++.h>

using namespace std;

vector<int> primes, ans[1000100], no;
int p[1000100];

int main() {
    ios::sync_with_stdio(false); cin.tie(); cout.tie(0);
    for (int i = 2; i * i <= 1000010; ++i) 
        for (int j = i + i; j <= 1000010; j += i) 
            p[j] = 1;

    for (int i = 2; i <= 1000010; ++i)
        if(!p[i]) primes.push_back(i);
        else no.push_back(i);

    int t;
    cin >> t;
    while(t--) {

        int n;
        cin >> n;

        for (int i = 0; i < 1000010; ++i)
            ans[i].clear();

        int cnt = 1;
        ans[0].push_back(1);
        for (auto x: primes) {
            if(x > n) break;
            ans[0].push_back(x);
        }

        int cur = 0;
        while(no[cur] <= n and cur < (int)no.size()) {
            ans[cnt].push_back(no[cur]);
            cur++;
            if(no[cur] - no[cur - 1] <= 1 and no[cur] <= n) {
                ans[cnt].push_back(no[cur]);
                cur++;
            }
            cnt++;
        }
        
        cout << cnt << "\n";
        for (int i = 0; i < cnt; ++i) {
            cout << ans[i].size() << " ";
            for (int j = 0; j < (int)ans[i].size(); ++j) {
                cout << ans[i][j];
                if(j + 1 < (int)ans[i].size()) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

