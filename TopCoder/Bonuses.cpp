#include <bits/stdc++.h>

using namespace std;

struct Bonuses {
    vector<int> getDivision(vector<int> points) {
    
        int tot = 0;
        priority_queue<pair<int,int> > q;
        for (int i = 0; i < (int) points.size(); ++i) {
            tot += points[i];
            q.push({points[i], -i});
        }
        
        vector<int> ans;
        
        int cur = 100;
        for (int i = 0; i < (int)points.size(); ++i) {
            ans.push_back(100 * points[i] / tot);
            cur -= ans.back();
        }

        while(cur--) {
            ans[-q.top().second]++;
            q.pop();
        }
        
        return ans;
    }
};


int main() {
        
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    Bonuses B;

    auto p = B.getDivision(v);

    for (auto x: p)
        cout << x << " ";
    cout << "\n";
    return 0;
}

