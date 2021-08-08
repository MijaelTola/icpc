#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,q;
    cin >> n >> q;

    vector<int> v;

    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
    }

    while(q--) {
        string a,b;
        cin >> a >> b;
        int da = stoi(a.substr(1));
        int db = stoi(b.substr(1));
        int aa = 0, bb = 0;

        while(v[aa] != da)
            aa++;

        while(v[bb] != db)
            bb++;

        if(aa > bb) {
            vector<int> re;
            for (int i = 0; i < bb; ++i)
                re.push_back(v[i]);

            for (int i = bb + 1; i <= aa; ++i) 
                re.push_back(v[i]);
            
            re.push_back(v[bb]);
            for (int i = aa + 1; i < n; ++i)
                re.push_back(v[i]);
            v = re;
        }
    }

    for (int i = 0; i < (int)v.size(); ++i) {
        cout << "T" << v[i];
        if(i + 1 < (int)v.size())
            cout << " ";
    }
    cout << "\n";


    return 0;
}

