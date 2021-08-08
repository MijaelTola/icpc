#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> v;

    for (int i = 0; i < 3; ++i) {
        int x;
        cin >>  x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    bool flag = 0;
    do {
        flag |= (v[2] - v[1] == v[1] - v[0]);
    } while(next_permutation(v.begin(), v.end()));

    if(flag) cout << "Yes\n";
    else cout << "No\n";
            
    
    return 0;
}

