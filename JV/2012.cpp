#include <bits/stdc++.h>

using namespace std;

set<int> s[100010];
set<int> se[100010];

int p[200010];
int p2[200020];

int findA(int x) {
    if(x == p[x]) return x;
    return p[x] = findA(p[x]);
}

void mergeA(int x, int y) {
    p[findA(y)] = findA(x);
}

int findE(int x) {
    if(x == p2[x]) return x;
    return p2[x] = findE(p2[x]);
}

void mergeE(int x,int y) {
    p[findE(y)] = findE(x);
}

int main() {

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        char c;
        int x,y;
        cin >> c >> x >> y;
        
        if(c == 'A') {
            s[x].insert(y);
            s[y].insert(x);
            mergeA(x,y);
        }
        if(c == 'E') {
            se[x].insert(y);
            se[y].insert(x);
            mergeE(x,y);
        }

        if(c == '?') {

            if(s[x].count(y)) {
                if(!se[x].count(y)) {
                    if(findA(x) == findA(y) and findE(x) != findE(y)) {
                        cout << "Amigos\n";
                        continue;
                    }
                }
                cout << "Error\n";
                continue;
            }

            if(se[x].count(y)) {
                if(!s[x].count(y)) {
                    if(findA(x) != findA(y) and findE(x) == findE(y)) {
                        cout << "Enemigox\n";
                        continue;
                    }
                }
                cout << "Error\n";
                continue;
            }
            cout<< "?\n";
        }
    }
    return 0;
}

