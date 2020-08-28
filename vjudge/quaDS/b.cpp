#include <bits/stdc++.h>

using namespace std;

int ini[26];
int fin[26];
bool g[26];

int main() {

    memset(ini, -1, sizeof ini);
    int n,k;
    string s;

    cin >> n >> k >> s;

    for (int i = 0; i < n; ++i) {
        if(ini[s[i] - 'A'] == -1)
            ini[s[i] - 'A'] = i;
        fin[s[i] - 'A'] = i;
    }

    for (int i = 0; i < n; ++i) {
        int x = s[i] - 'A';
        if(!g[x]) {
            if(k) k--;
            else return cout << "YES\n",0;
            g[x] = 1;
        }
        if(i == fin[x]) {
            g[x] = 0;
            k++;
        }
    }
    cout << "NO\n";
    return 0;
}

