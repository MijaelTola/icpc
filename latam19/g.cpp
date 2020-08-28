#include <bits/stdc++.h>

using namespace std;


struct SuffixArray{
    int order[300010];
    int cpyorder[300010];
    int count[300010];
    int class1[300010];
    int class2[300010];
    string s;
    int sz;
    void sortcharacter(){
        for (int i = 0; i < sz; ++i)
            count[s[i]-'A'+1]++;

        count[0] = 1;

        for (int i = 1; i < 28; ++i)
            count[i] += count[i-1];

        for (int i = sz; i >= 0; --i){
            int c = s[i]-'A'+1;
            if(s[i] == '$') c = 0;
            count[c]--;
            order[count[c]] = i;
        }
    }

    void ComputeCharClasses(){
        class1[order[0]] = 0;
        for (int i = 1; i < sz; ++i){
            if(s[order[i]]!=s[order[i-1]])
                class1[order[i]] = class1[order[i-1]]+1;
            else class1[order[i]] = class1[order[i-1]];
        }
    }
    
    void SortDoubled(int l){
        memset(count,0,sizeof count);
        for (int i = 0; i < sz; ++i)
            cpyorder[i] = order[i];

        for (int i = 0; i < sz; ++i)
            count[class1[i]]++;
        
        for (int i = 1; i < sz; ++i)
            count[i] += count[i-1];
        
        for (int i = sz-1; i >= 0; --i){
            int start = (cpyorder[i] - l + sz)%sz;
            int cl = class1[start];
            count[cl]--;
            order[count[cl]] = start;
        }
    }

    void updateClasses(int l){
        for (int i = 0; i < sz; ++i)
            class2[i] = class1[i];
        class1[order[0]] = 0;
        for (int i = 1; i < sz; ++i){
            int cur = order[i];
            int prev = order[i-1];
            int mid = (cur+l)%sz;
            int midp = (prev+l)%sz;
            if(class2[cur] != class2[prev] or class2[mid] != class2[midp])
                class1[cur] = class1[prev]+1;
            else class1[cur] = class1[prev];
        }
    }

    int cmp(string &pattern,int mid,int m){
        for (int i = order[mid],j = 0; j < m and i < sz; ++i,++j){
            if(pattern[j]!=s[i])
                return (pattern[j] < s[i])? -1:1;
        }
        return 0;
    }

    bool f(string pattern) {
        int a = -1, b = sz, m = pattern.size();
        while(b - a > 1) {
            int mid = (a + b) / 2;
            int res = cmp(pattern, mid, m);
            if(res >=  0) a = mid;
            else b = mid;
        }
        if(cmp(pattern, a, m) != 0) return 0;
        return 1;
    }

    SuffixArray(string x){
        s = x;
        sz = s.size();
        sortcharacter();
        ComputeCharClasses();
        int l = 1;
        while(l < sz){
            SortDoubled(l);
            updateClasses(l);
            l *= 2;
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string x;
    cin >> x;
    
    set<char> p;
    for (char c: x)
        p.insert(c);
    x += '$';
    SuffixArray SA(x);
    int q;
    cin >> q;

    while(q--) {
        string s;
        cin >> s;
        
        bool flag = 1;
        for (char c: s) 
            flag &= p.count(c);
        
        if(!flag) {
            cout << "-1\n";
            continue;
        }
        int pos = 0;
        
        int ans = 0;
        while(pos < (int)s.size()) {
            int a = pos, b = (int)s.size();
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(SA.f(s.substr(pos, mid + 1 - pos))) a = mid;
                else b = mid;
            }
            pos = a + 1;
            ans++;
        }
        cout << ans << "\n";
        
    }
    return 0;
}

