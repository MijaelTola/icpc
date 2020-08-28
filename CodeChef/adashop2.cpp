#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > ans;

int main() {


    auto refill = [] (bool flag) {
        if(!flag) ans.emplace_back(1, 7);
        ans.emplace_back(2, 8);
        ans.emplace_back(3, 7);
        ans.emplace_back(4, 8);
        ans.emplace_back(1, 5);
        ans.emplace_back(2, 4);
        ans.emplace_back(1, 3);
        ans.emplace_back(6, 8);
        ans.emplace_back(7, 7);
        ans.emplace_back(8, 8);
        ans.emplace_back(1, 1);
        ans.emplace_back(2, 2);
        ans.emplace_back(3, 1);
        ans.emplace_back(8, 6);
        ans.emplace_back(7, 5);
        ans.emplace_back(8, 4);
        ans.emplace_back(5, 1);
        ans.emplace_back(6, 2);
        ans.emplace_back(7, 1);
        ans.emplace_back(8, 2);
    };

    int t;
    cin >> t;
    while(t--) {
        ans.clear();
        int a,b;
        cin >> a >> b;
        pair<int,int> p = {a, b};
        int da = a, db = b;
        bool flag = 0;
        if(a + b != 8) {
            flag = 1;
            while(a <= 8 and b <= 8) {
                if(a + b == 8) {
                    p = {a, b};
                    break;
                }
                a++,b++;
            }
        
            if(p.first + p.second == 8) flag = 1;
            else {
                a = da, b = db;
                while(a >= 1 and b >= 1) {
                    if(a + b == 8) {
                        p = {a, b};
                        break;
                    }
                    a--,b--;
                }
            }
        }

        if(flag) ans.push_back(p);
        
        refill((p.first == 1 and p.second == 7));
        
        assert(ans.size() <= 64);
        cout << ans.size() << "\n";
        for (auto p: ans)
            cout << p.first << " " << p.second << "\n";
    }
    return 0;
}

