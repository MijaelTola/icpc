#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool first = 1;
    while(cin >> n) {
        if(first) first = 0;
        else cout << "\n";
        unordered_map<string,int> mp;
        cin.ignore();
        string s;
        while(getline(cin, s) and s != "EndOfText") {
            string cur = "";
            for (int i = 0; i < (int)s.size(); ++i) {
                s[i] = tolower(s[i]);
                if(('A' <= s[i] and s[i] <= 'Z') 
                        or ('a' <= s[i] and s[i] <= 'z')) cur += s[i];
                else {
                    mp[cur]++;
                    cur = "";
                }
            }
            if(cur != "") mp[cur]++;

        }
        vector<string> ans;
        for (auto x: mp) 
            if(x.second == n) 
                ans.push_back(x.first);
        if(!ans.size()) cout << "There is no such word.\n";
        else {
            sort(ans.begin(), ans.end());
            for (string x: ans)
                cout << x << "\n";
        }
    }
    return 0;
}

