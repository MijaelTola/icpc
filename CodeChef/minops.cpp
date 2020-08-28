#include <bits/stdc++.h>

using namespace std;

int is[1000100];

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        string s,r;
        cin >> s >> r;
        int n = s.size();
        for (int i = 0; i < n; ++i) 
            is[i] = 0;

        for (int i = 0; i < n; ++i) 
            is[i] = s[i] == r[i];

        int last = is[0];
        int cnt = 0;

        long long total = 0;

        priority_queue<int> q;
        long long k = 0;
        bool first = 1;
        for (int i = 0; i < n; ++i) {
            if(is[i] == last) cnt++;
            else {
                if(last) {
                    if(first) first = 0;
                    else q.push(-cnt);
                } else {
                    total += cnt;
                    k++;
                }
                cnt = 1;
            }
            last = is[i];
        }

        if(!last) {
            total += cnt;
            k++;
        }
        
        bool flag = 1;

        while(!q.empty() and flag) {
            flag = 0;
            long long val = -q.top();
            q.pop();
            if((total + val) * max(1ll,k - 1) < total * max(1ll,k)){
                k--;
                k = max(1ll,k);
                total += val;
                flag = 1;
            }
        }
        cout << total * k << "\n";

    }

    return 0;
}

