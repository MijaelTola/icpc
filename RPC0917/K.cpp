#include <bits/stdc++.h>

using namespace std;

int n;
int v[500010];
bitset<500010> ulam;
long long st[500010];
long long st2[500010];
int pt[500010];
int x = 31;
int p = 1000000007;

void update(int pos, int value){
    for (st[pos += n] = value; pos > 1; pos >>= 1)
        st[pos>>1] = (st[pos] + st[pos^1]) % p;
}

long long query(int l,int r){
    long long ans = 0LL;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) ans = (ans + st[l++]) % p;
        if(r & 1) ans = (ans + st[--r]) % p;
    }
    return ans;
}


void update2(int pos, int value){
    for (st2[pos += n] = value; pos > 1; pos >>= 1)
        st2[pos>>1] = (st2[pos] + st2[pos^1]) % p;
}

int query2(int l,int r){
    long long ans = 0LL;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) ans = (ans + st2[l++]) % p;
        if(r & 1) ans = (ans + st2[--r]) % p;
    }
    return ans;
}

long long modpow(long long base, long long e, long long mod) {
	if (e == 0)return 1;
	return (modpow((base * base)%mod, e/2,mod) * (e&1?base:1) )%mod;
}

long long modInverse(long long a, long long mod){
    return modpow(a, mod - 2, mod);
}

void gen(){
    pt[0] = 1;
    for (int i = 1; i < 500010; ++i)
        pt[i] = (pt[i - 1] * 31) % p;
    
    ulam[1] = ulam[2] = 1;
    
    for (int i = 3; i <= 100000; ++i){
        int cur = 0;
        for (int j = 1; j < i; ++j){
            int x = j;
            int y = i - j;
            if(ulam[x] and ulam[y] and x != y) cur++;
        }
        if(cur == 2) ulam[i] = 1;
    }
}


int main(){
    gen();
    while(scanf("%d",&n) != EOF){
        memset(st, 0,sizeof st);
        memset(st2, 0 ,sizeof st);
        for (int i = 0; i < n; ++i)
            scanf("%d", v + i);

        for (int i = 0; i < n; ++i){
            update(i, (v[i] * pt[i]) % p);
            update2(i, (v[i] * pt[(n - 1) - i]) % p);
        }
        int q;
        scanf("%d",&q);
        while(q--){
            char c[1];
            int l,r;
            scanf("%s %d %d",c,&l,&r);
            if(c[0] == 'G'){
                l--,r--;
                long long L2 = query2(l, n);
                long long R2 = query2(r + 1, n);
                long long L = query(0, l - 1);
                long long R = query(0, r);
                long long inv = modInverse(pt[(n - 1) - r], p);
                long long hsh = ((((L2 - R2) * inv) % p) + p) % p;
                inv = modInverse(pt[l], p);
                long long hsh2 = ((((R - L) * inv) % p) + p ) % p;
                cout << hsh << " " << hsh2 << "\n";
                puts((hsh == hsh2 and (ulam[v[l]] or ulam[v[r]])) ? "Y" : "N");
            }else{
                l--;
                update(l, (r * pt[l]) % p);
                update2(l, (r * pt[(n - 1) - l]) % p);
                v[l] = r;
            }
        }
    }
    return 0;
}

