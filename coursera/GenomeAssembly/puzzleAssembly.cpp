#include <bits/stdc++.h>

using namespace std;

const string black = "black";
vector<vector<string> > v;

bool vis[30];
int c[30][30];
int n = 5, m = 5;

void printTuple(vector<string> a) {
    string a1,a2,a3,a4;
    a1 = a[0]; a2 = a[1]; a3 = a[2]; a4 = a[3];
    cout << "(" << a1 << "," << a2 << "," << a3 << "," << a4 << ")";
}

bool same(vector<string> a, vector<string> b, int c) {
    string a1,a2,a3,a4,b1,b2,b3,b4;
    a1 = a[0]; a2 = a[1]; a3 = a[2]; a4 = a[3];
    b1 = b[0]; b2 = b[1]; b3 = b[2]; b4 = b[3];
    if(c == 0) return a1 == b3; //up of a
    if(c == 1) return a2 == b4; //left of a
    return 0;
}


bool check() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printTuple(v[c[i][j]]);
            if(j + 1 < n) cout << ";";
        }
        cout << "\n";
    }
    return 1;
}

void f(int x, int y) {
    if(x == n) {
        if(check()) exit(0);
        return;
    }

    if(y == m) {
        f(x + 1, 0);
        return;
    }

    for (int i = 0; i < (int)v.size(); ++i) {
        if(!vis[i]) {
            string a1,a2,a3,a4;
            a1 = v[i][0]; a2 = v[i][1]; a3 = v[i][2]; a4 = v[i][3];
            bool flag = 1;

            vis[i] = 1;
            c[x][y] = i;

            if(x == 0) flag &= a1 == black;
            if(x == n - 1) flag &= a3 == black;
            if(y == 0) flag &= a2 == black;
            if(y == n - 1) flag &= a4 == black;

            if(x > 0) flag &= same(v[c[x][y]], v[c[x - 1][y]], 0);
            if(y > 0) flag &= same(v[c[x][y]], v[c[x][y - 1]], 1);
            if(flag) f(x, y + 1);
            vis[i] = 0;
        }
    }
}

int main() {

    string s;
    while(cin >> s) {
        string color = "";
        vector<string> b;
        for (int i = 1; i < (int)s.size() - 1; ++i) {
            if(s[i] != ',') color += s[i];
            else b.push_back(color), color = "";
        }
        b.push_back(color);
        v.push_back(b);
    }


    f(0,0);

    return 0;
}

