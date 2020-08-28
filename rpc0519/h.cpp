#include <bits/stdc++.h>

using namespace std;

int alpha[256];
int betta[256];
int main() {
    string a,b;
    int x;
    cin >> a >> x >> b;
    
    char cur = '?';
    int cnt = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if('A' <= a[i] and a[i] <= 'Z') {
            if(cnt == 0) cnt++;
            alpha[(int)cur] += cnt;
            cnt = 0;
            cur = a[i];
        } else cnt = cnt * 10 + (a[i] - '0');
    }
    
    if(cnt == 0) cnt++;
    alpha[(int)cur] += cnt;
    cnt = 0;
    for (char i = 'A'; i <= 'Z'; i++)
        alpha[(int)i] *= x;

    cur = '?';
    cnt = 0;
    for (int i = 0; i < (int)b.size(); ++i) {
        if('A' <= b[i] and b[i] <= 'Z') {
            if(cnt == 0) cnt++;
            betta[(int)cur] += cnt;
            cnt = 0;
            cur = b[i];
        } else cnt = cnt * 10 + (b[i] - '0');
    }
    
    if(cnt == 0) cnt++;
    betta[(int)cur] += cnt;
    
    int ans = 1e9;
    for (char i = 'A'; i <= 'Z'; i++)
        if(betta[(int)i]) 
            ans = min(ans, alpha[i] / betta[i]);
        
    cout << ans << "\n";
    return 0;
}

