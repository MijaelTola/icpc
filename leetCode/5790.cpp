#include <bits/stdc++.h>

using namespace std;

int v[101][100010];
vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
    
    memset(v, 0, sizeof v);


    for (int i = 0; i < (int)nums.size(); ++i) {
        v[nums[i]][i] = 1;
    }
    
    for (int i = 0; i < 101; ++i) {
        for (int j = 1; j < 100010; ++j) {
            v[i][j] += v[i][j - 1];
        }
    }

    vector<int> ans;

    for (auto q: queries) {
        int l = q[0], r = q[1];
        
        auto check = [&](int i, int l, int r) {
            int dl = v[i][r];
            if(l) dl -= v[i][l - 1];
            return dl > 0;
        };

        vector<int> dv;
        for (int i = 1; i <= 100; ++i) {
            if(check(i, l, r)) dv.push_back(i);
        }

        int res = 1e9;
        for (int i = 0; i < (int)dv.size() - 1; ++i) {
            res = min(res, abs(dv[i] - dv[i + 1]));
        }

        if(res != 1e9) ans.push_back(res);
        else ans.push_back(-1);
    }

    return ans;
}

int main() {

    vector<int> a = {1,3,4,8};
    vector<vector<int> > b = {{0,1},{1,2},{2,3},{0,3}};

    auto ans = minDifference(a, b);

    for (auto x: ans)
        cout << x << "\n";

    return 0;
}

