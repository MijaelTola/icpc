#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p;
    string s;
    cin >> n >> p >> s;

    for(int i=0; i<n; ++i){
        if(i>=p){
            if(s[i - p] == '.' && s[i] == '.') s[i - p] = '0', s[i] = '1';
            else if(s[i - p] == '.') s[i-p] = (s[i] - '0' + 1) % 2 + '0';
            else if(s[i] == '.') s[i] = (s[i - p] - '0' + 1) % 2 + '0';
        }
    }

    bool flag = 0;
    for(int i=0; i<n; ++i) {
        if(s[i] == '.') s[i] = '0';
        if(i >= p && s[i - p] != s[i]) flag = 1;
    }
    if(flag) cout << s;
    else cout << "No";
}

