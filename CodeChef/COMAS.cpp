#include <bits/stdc++.h>

using namespace std;

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int n,t;
bool vis[101];
int v[101];
pair<int,int> maxi[101];

int main() {

    t = in();
    while (t--) {
        memset(vis, 0, sizeof vis);
        n = in();
        int pos = 0, c = 0, x, y;
        while(true) {
            c++;
            pos = 0;
            int p = 1;
            while(pos < 6 and p <= n) {
                if(!vis[p]) v[pos++] = p;
                p++;
            }
            if(pos < 6) break;
            printf("? ");
            for (int i = 0; i < pos - 1; ++i) 
                printf("%d ", v[i]);
            printf("\n");
            fflush(stdout);
            x = in(), y = in();
            vis[x] = vis[y] = 1;
        }

        if(pos < 6) v[pos++] = x;
        if(pos < 6) v[pos++] = y;
        int ans = -1;

        int a = -1, b = -1, cc = -1;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < pos; ++i) {
            c++;
            printf("? ");
            for (int j = 0; j < pos; ++j) {
                if(j == i) continue;
                printf("%d ", v[j]);
            }
            printf("\n");
            fflush(stdout);
            x = in(), y = in();
            maxi[v[i]] = {x,y};
            vis[x] = vis[y] = 1;
            if(a == -1 and b == -1) {
                a = x;
                b = y;
                continue;
            }
            if(y == b) continue;
            if(y == a) continue;

            if(x == b) {
                a = x;
                b = y;
            }

        }

        for (int i = 0; i < pos; ++i) {
            int flag = 0;
            for (int j = 0; j < pos; j++) {
                if(j == i) continue;
                if(vis[v[j]]) flag++;
            }
            if(flag != 3) continue;
            pair<int,int> p = maxi[v[i]];
            if(p.second != b) {
                ans = v[i];
                break;
            }

        }
        printf("! %d\n", ans);
        fflush(stdout);
    } 
    return 0;
}


