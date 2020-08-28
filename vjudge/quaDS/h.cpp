#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {

    int n;
    cin >> n;
   
    memset(v, -1, sizeof v);

    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    
    
    vector<int> s;
    s.push_back(0);
    
    vector<pair<int,int> > ans;
    for (int i = 1; i <= n + 1; ++i) {
        if(v[i] > v[s.back()]){
            s.push_back(i);
        }
        if(v[i] < v[s.back()]) {
            while(v[i] < v[s.back()]) {
                ans.emplace_back(s.back(), i - 1);
                v[s.back()]--;
                int p = s.size() - 2;
                if (v[s.back()] <= v[s[p]])
                    s.pop_back();
            }
        }
    }

    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < (int)ans.size() - 1; ++i) {
        auto p = ans[i];
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

