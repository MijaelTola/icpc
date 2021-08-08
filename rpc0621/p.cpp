#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    cin.ignore();

    set<string> con;

    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        string cur = "";
        vector<string> v;
        for (auto x: s) {
            if(x == ' ') {
                v.push_back(cur);
                cur = "";
            } else {
                cur += x;
            }
        }
        v.push_back(cur);

        int id = -1;
        for (int i = 0; i < (int)v.size(); ++i) {
            if(v[i] == "->") id = i;
        }
        
        bool flag =  1;
        for (int i = 0; i < id; ++i) {
            flag &= con.count(v[i]);    
        }

        if(!flag) return cout << (i + 1) << "\n", 0;

        for (int i = id + 1; i < (int)v.size(); ++i) {
            con.insert(v[i]);           
        }
    }
    cout << "correct\n";
    return 0;
}

