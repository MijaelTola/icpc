#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        vector<int>a,b;
        int n;
        cin >> n;
        
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            
            auto get = [&] (int x) {
                int ans = 0;
                while(x > 0) {
                    ans += x % 10;
                    x /= 10;
                }
                return ans;
            };
            a.push_back(get(x));
            b.push_back(get(y));
        }

        int da = 0, db = 0;
        
        while(a.size()) {
            if(a.back() > b.back()) da++;
            if(a.back() < b.back()) db++;
            if(a.back() == b.back()) da++,db++;
            a.pop_back();
            b.pop_back();
        }

        if(da > db) {
            cout << "0 " << da << "\n";
        }

        if(db > da) {
            cout << "1 " << db << "\n";
        }

        if(db == da) {
            cout << "2 " << da << "\n";
        }
    }
    return 0;
}

