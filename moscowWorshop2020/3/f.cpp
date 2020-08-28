#include <bits/stdc++.h>

using namespace std;

vector<long long> v;

int main() {

    long long n,c,y;
    cin >> n >> c >> y;
        
    long long  dc = -1;
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        total += x;
        if(c - 1 != i) v.push_back(x);
        else dc = x;
    }

    if(n == 2) {
        cout << v.back() << " " << v.back() * y + dc << "\n";
        return 0;
    }

    sort(v.begin(), v.end());

    bool flag = 1;

    for (int i = 1; i < (int)v.size(); ++i) {
        int val = (v[i] - v[i - 1]);
        flag &= val % (y + 1)== 0;
    }

    if(!flag) return cout << "impossible\n",0;
    long long ans = 0;
    long long current = 0;
    
    for (int i = v.size() - 1; i > 0; i--) {
		long long df = v[i] - (v[i - 1] - ans);
      	long long cnt = df / (y + 1);
      	current = (v[i - 1] - ans) + cnt * y;
        v[i - 1] = current;
        dc -= cnt;
      	ans += cnt;
    }

    if(current * y + dc < total) return cout << "impossible\n", 0;
    
    cout << ans + current << " " << current * y + dc<< "\n";
    return 0;
}
