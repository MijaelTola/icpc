#include <bits/stdc++.h>

using namespace std;


int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    auto get = [&] (int n) {
        long long ans = 0; 
        while (n > 0) { 
            if (n % 2 == 0) 
                ans++; 
            n >>= 1;
        } 

        return 1LL << ans; 
    };

    cout << "enst\n";
    int n;

    vector<pair<int,int> > ans;
    int cur = 0;
    while(cin >> n) {
        ans.push_back({n, cur++});
    }

    //cout << ans.size() << "aca\n";

    int ini = 0;

    long long a = 0;
    vector<pair<int, long long> > b;
    for (auto [x,y]: ans) {
        for (; ini <= x; ++ini) {
            //cout << ini << " " << x << "\n";
            a += get(ini);
        }

        b.push_back({y, a});
    }


    sort(b.begin(), b.end());

    for (auto [x,y]: b)
        cout << y << "\n";


    return 0;
}
