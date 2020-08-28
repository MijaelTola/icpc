#include <bits/stdc++.h>

using namespace std;

int p[1000100];
vector<int> prime;
int d[1000100];
bool ver[1000100];
void criba(){
    memset(p, -1,sizeof p);
    for (int i = 2; i*i < 1000100; ++i){
        int c = i + i;
        while(c < 1000100){
            p[c] = i;
            c += i;
        }
    }
    p[0] = p[1] = 1;
    for (int i = 2; i < 1000100; ++i)
        if(p[i] == -1) prime.push_back(i);

    for (int i = 0; i < (int)prime.size(); ++i){
        int c = prime[i];
        while(c < 1000100){
            d[c] = prime[i];
            c += prime[i];
        }
    }

}

vector<pair<int,int> > v;
vector<pair<int,pair<int,int> > > idx;
bool in[1000100];
int main(){
    memset(in,false,sizeof in);
    memset(ver,false,sizeof ver);
    criba();

    int n; 
    scanf("%d", &n);

    for (int i = 0; i < n; ++i){
        int x; scanf("%d",&x);
        if(!in[x]){
            in[x] = 1;
            v.push_back(make_pair(x,i));
        }
    }
    
    for (int i = 0; i < (int)v.size(); ++i){
        int x = v[i].first;
        int div = d[x];
        int cur = 0;
        while(x > 1){
            div = d[x];
            x /= div;
            cur++;
        }
        if(!ver[cur]) idx.push_back(make_pair(cur,make_pair(v[i].second, 
                        v[i].first)));
        ver[cur] = 1;
    }
    
    sort(idx.begin(),idx.end());
    
    cout << idx[0].second.first << " " << idx[0].second.second << "\n";
    sort(v.begin(),v.end());

    int q; 
    scanf("%d",&q);
    while(q--){
        int x; scanf("%d",&x);
        int f = x;
        int div = d[x];
        int ans = 1;
        int id1 = 0;
        if(v[id1].first == x) id1 = 1;
        x /= div;
        bool found = false;
        while(x > 1){
            int pos = lower_bound(v.begin(), v.end(), 
                    make_pair(x,0)) - v.begin();
            if(v[pos].first == x){
                id1 = v[pos].second;
                found = 1;
                break;
            }
            div = d[x];
            x /= div;
            ans++;
        }
        if(!found){
            ans += idx[id1].first;
            int cur = idx[id1].second.second;
            id1 = idx[id1].second.first;
            int ans2 = 0;
            found = false;
            while(cur > 1){
                if(f % cur == 0){
                    found = 1;
                    break;
                }
                int div = d[cur];
                cur /= div;
                ans2++;
            }
            if(found){
                f /= cur;
                while(f > 1){
                    int div = d[f];
                    f /= div;
                    ans2++;
                }
            }else ans2 = 1e9;
            ans = min(ans,ans2);
        }

        printf("%d %d\n",id1 + 1, ans);
    }
    return 0;
}

