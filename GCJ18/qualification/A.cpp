#include <bits/stdc++.h>

using namespace std;

int d;string s;
bool find() {
    int l = 0;
    while(l + 1 < (int)s.size()) {
        if(s[l] == 'C' and s[l + 1] == 'S') {
            swap(s[l],s[l + 1]);
            return 1;
        }
        l++;
    }
    return 0;
}

long long calculate() {
    long long damage = 0;
    long long cur = 1;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == 'S') damage += cur;
        else cur *= 2;
    }
    return damage;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    int k = 1;
    while(t--) {
        cin >> d >> s;
        long long cur = calculate();
        int ans = 0;
        while(cur > d) {
            if(!find()) goto noanswer;
            cur = calculate();
            ans++;
        }
        
        cout << "Case #"<<k++ << ": "<< ans << "\n";
        continue;
        noanswer:
        cout << "Case #"<< k++ << ": IMPOSSIBLE\n";
    }
    return 0;
}

