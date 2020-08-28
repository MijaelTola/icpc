#include <bits/stdc++.h>

using namespace std;

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int n,t;
bool vis[101];
int v[101];
int bb[101];
int fix[101];
void init() {
    for (int i = 0; i < 101; ++i) {
        vis[i] = 0;
        fix[i] = 0;
    }
}

vector<int> per;

pair<int,int> check() {
    pair<int,int> pr;  
    int cnt = 0;
    for (int i = 0; i < (int)per.size(); ++i) {

        for (int j = 0; j < 5; ++j) {
            if(per[i] == v[j]) {
                if(cnt == 2) pr.first = v[j];
                if(cnt == 3) pr.second = v[j];
                cnt++;
            }
        }
    }
    return pr;   
}

pair<int,int> check2() {
    pair<int,int> pr;
    int cnt = 0;
    for (int i = 0; i < (int)per.size(); ++i) {

        for (int j = 0; j < 5; ++j) {
            if(per[i] == bb[j]) {
                if(cnt == 2) pr.first = bb[j];
                if(cnt == 3) pr.second = bb[j];
                cnt++;
            }
        }
    }
    return pr;
}

pair<int,int> maxi[101];
int main() {
    
    t = in();
    /*for (int i = 1; i <= 8; i++) {
        cout << i << " wtf\n";
        per.push_back(i);
    }
*/
    while (t--) {
        init();
        n = in();
        //cout << n << "\n";
        /*for (int e: per)
            cout << e << " ";
        cout << "\n";*/
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
            /*cout << "? ";
            for (int i = 0; i < pos - 1; ++i) {
                cout << v[i] << " ";
            }
            cout << "\n";*/
            //pair<int,int> pr = check();
            printf("? ");
            for (int i = 0; i < pos - 1; ++i) 
                printf("%d ", v[i]);
            printf("\n");
            fflush(stdout);
            x = in(), y = in();
            //x = pr.first;
            //y = pr.second;
            //cout << x << " " << y << "\n";
            vis[x] = vis[y] = 1;
        }
        if(pos < 6) v[pos++] = x;
        if(pos < 6) v[pos++] = y;
        int ans = -1;
        int a = -1, b = -1, cc = -1;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < pos; ++i) {
            c++;
            /*int pos2 = 0;
            for (int j = 0; j < pos; ++j) {
                if(j == i) continue;
                bb[pos2++] = v[j];
            }*/
            printf("? ");
            for (int j = 0; j < pos; ++j) {
                if(j == i) continue;
                printf("%d ", v[j]);
            }
            printf("\n");
            fflush(stdout);
            x = in(), y = in();
            
            /*cout << "? ";
            for (int i = 0; i < pos2; ++i) 
                cout << bb[i] << " ";
            cout << "\n";

            pair<int,int> pr = check2();*/
            //cout << x << " " << y << "\n";
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

        // find the order of this 3 numbers
        for (int i = 0; i < pos; ++i) {
            int flag = 0;
            for (int j = 0; j < pos; j++) {
                if(j == i) continue;
                //cout << v[j] << " ";
                if(vis[v[j]]) flag++;
            }
            //cout << "\nporque\n";
            //cout << flag << "\n";
            if(flag != 3) continue;
            //cout << "without " << v[i] << "\n";
            pair<int,int> p = maxi[v[i]];
            //cout << p.first << " " << p.second << " \n";
            if(p.second != b) {
              //  cout << "find\n";
                ans = v[i];
                break;
            }

        }
        /*cout << ans << " " << per[per.size() - 1] << " \n";
        if(ans != per[per.size() - 1]) {
            cout << "############### CASO\n";
            for (auto e: per)
                cout << e << " ";
            cout << "\n";
            return 0;
        }
        cout << "llega aca\n";*/
        printf("! %d\n", ans);
        fflush(stdout);
    } 
    return 0;
}


