#include <bits/stdc++.h>

using namespace std;

int t,n,m,s,k,sz;
int alp[27], alp2[27],G[20][27];
int dp[100010][20];
char ss[100010];
bool fin[27],is[27];
int f(int pos, int state) {
    if(pos == sz) return fin[state];
    int &ans = dp[pos][state];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < 27; ++i) 
        for (int j = 0; j < 19; ++j) 
            if((G[state][i] & (1 << j)) and (char)(i + 'a') == ss[pos] and is[i])  {
                ans |= f(pos + 1, j);
            }
    return ans;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        memset(alp, 0, sizeof alp);
        memset(alp2, 0, sizeof alp2);
        memset(fin, 0,sizeof fin);
        memset(is, 0, sizeof is);;
        memset(G, 0, sizeof G);

        scanf("%d %d %d %d", &n, &m, &s, &k);
        for (int i = 0; i < s; ++i) {
            char x; 
            cin >> x;
            alp[x - 'a'] = i;
            alp2[i] = x - 'a';
            is[x - 'a'] = 1;
        }

        for (int i = 0; i < k; ++i) {
            int x; 
            scanf("%d", &x);
            fin[x] = 1;
        }
        
        for (int i = 0; i < m; ++i) {
            int x,y;
            char z;
            cin >> x >> y >> z;
            G[x][z - 'a'] = G[x][z - 'a'] | (1 << y);
        }
        
        int q;
        scanf("%d", &q);
        while(q--) {
            memset(dp, -1, sizeof dp);
            scanf("%s", ss);
            sz = strlen(ss);
            if(f(0, 0)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

