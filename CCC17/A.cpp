#include <bits/stdc++.h>

using namespace std;

char s[1000100];
int v[100010];
int answer[100010];
pair<pair<int,int> ,int> queries[100010];
long long x = 31;
long long p = 67280421310721LL;
//int p = 1000000007;
int block_size;
long long h(int sz){
    long long hsh = 0;
    for (int i = sz - 1; i >= 0; --i){
        hsh = (((hsh * x + s[i]) % p) + p) % p;
    }
    return hsh;
}

bool cmp(const pair< pair<int,int>, int> &x,
        const pair< pair<int,int>, int> &y){
    
    int dx = x.first.first / block_size;
    int dy = y.first.first / block_size;
    if(dx != dy) return dx < dy;
    return x.first.second < y.first.second;
}
map<long long,int> mp;
int mapa[1000100];
int ans = 0;
void add(int x){
    if(mapa[x] == 0) ans++;
    mapa[x]++;
}
void del(int x){
    mapa[x]--;
    if(mapa[x] == 0) ans--;
}
int main(){
    
    int n,q;
    scanf("%d %d",&n,&q);
    block_size = static_cast<int> (sqrt(n));
    int cnt = 1;
    for (int i = 0; i < n; ++i){
        scanf("%s",s);
        int sz = strlen(s);
        long long hashed = h(sz);
        if(!mp.count(hashed)) mp[hashed] = cnt++;
        v[i] = mp[hashed];
    }
    assert(cnt < 1000100);
    for (int i = 0; i < q; ++i){
        int x,y;
        scanf("%d %d",&x,&y);
        queries[i].first.first = x - 1;
        queries[i].first.second = y - 1;
        queries[i].second = i;
    }

    sort(queries, queries + q, cmp);

    int ml = 0, mr = -1;
    ans = 0;

    for (int i = 0; i < q; ++i){
        int left = queries[i].first.first;
        int right = queries[i].first.second;
        while(mr < right){
            mr++;
            add(v[mr]);
        }
        while(mr > right){
            del(v[mr]);
            mr--;
        }

        while(ml < left){
            del(v[ml]);
            ml++;
        }
        while(ml > left){
            ml--;
            add(v[ml]);
        }
        answer[queries[i].second] = ans;
    }

    for (int i = 0; i < q; ++i)
        printf("%d\n",answer[i]);
    return 0;
}
