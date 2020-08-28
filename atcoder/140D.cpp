#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;
vector<pair<int,pair<int,int> > > l,r;
int main() {

    cin >> n >> k >> s;
    char last = '#';
    int ini = -1, fin = -1;
    bool flag = 1;
    for (int i = 0; i < n; ++i) {
        if(s[i] == last) fin = i;
        else {
            if(ini != -1) {
                if(last == 'L') l.push_back({fin - ini + 1, {ini, fin}});
                else r.push_back({fin - ini + 1, {ini, fin}});
            }
            ini = fin = i;
            flag = !flag;
        }
        last = s[i];
    }
    
    
    sort(l.rbegin(), l.rend());
    sort(r.rbegin(), r.rend());
    string dl = s, dr = s;

    
    return 0;
}

