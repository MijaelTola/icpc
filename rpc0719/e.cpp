#include <bits/stdc++.h>

using namespace std;

bool p[10000010];
void criba() {
    memset(p, 0, sizeof p);
    for (int i = 2; i * i < 10000010; ++i) 
        for (int j = i + i; j < 10000010; j += i)  
            p[j] = 1;

    p[0] = p[1] = 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    criba();
    int t;
    cin >> t;
    while(t--) {
        string a,b;
        cin >> a >> b;
        if(a == b) {
            cout << "2 2\n";
            continue;
        }

        string da = "", db = "";
        for (char x: a)
            if(x != '.') da += x;

        for (char x: b)
            if(x != '.') db += x;
        
        int x = 0, y = 0;
        for (int i = 0; i < (int)da.size(); ++i) 
            x = x * 10 + (int)(da[i] - '0');
        
        for (int i = 0; i < (int)db.size(); ++i) 
            y = y * 10 + (int)(db[i] - '0');
        
        int g = __gcd(x,y);
        x /= g, y/=g;
        if(!p[x] and !p[y]) cout << x << " " << y << "\n";
        else cout << "impossible\n";
    }
    return 0;
}

