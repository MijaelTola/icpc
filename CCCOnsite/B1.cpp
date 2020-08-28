#include<bits/stdc++.h>


using namespace std;

vector<int> primes;
pair<pair<int,int> ,pair<int,int> > vis[1000100];

bool cmp(const pair<pair<int,int>, pair<int,int> > &a, const pair<pair<int,int> , pair<int,int> > &b){
    if(a.first.first == b.first.first) return a.second.second < b.second.second;
    return a.first.first < b.first.first;
}
int sieve[1000100];
vector<int> f;

void factor(int n){
    f.clear();
	int index = 0;
	int pf = primes[0];
	while(pf*pf <= n){
        while(n % pf==0){
            f.push_back(pf);
			n /= pf;
		}
        pf = primes[++index];
	}
	if(n != 1) f.push_back(n);
}
vector<pair<int,pair<int,int> > > v;
int main(){
	memset(sieve,false,sizeof sieve);	
	for (int i = 2; i*i < 1000100; ++i){
		int c = i + i;
		while(c < 1000100){
			sieve[c] = true;
			c += i;
		}
	}

    for (int i = 2; i < 1000100; ++i){
        if(!sieve[i])primes.push_back(i);
    }
    for (int i = 0; i < 1000100; ++i)
        vis[i].first.first = vis[i].second.second = 1e9;

    factor(4);
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d",&x);
        factor(x);
        for (int j = 0; j < (int)f.size(); ++j){
            int cur = 1;
            for (int k = j; k < (int)f.size(); ++k){
                cur *= f[k];
                if((int)f.size() - (k - j + 1) < vis[cur].first.first){
                    vis[cur].first.first = (int)f.size() - (k - j + 1);
                    vis[cur].first.second = f.size();
                    vis[cur].second.first = x;
                    vis[cur].second.second = i;
                }
            }
        }
        v.push_back({f.size(),{i,x}});
    }
    
    sort(v.begin(),v.end());
    
    int q; 
    scanf("%d", &q);
    while(q--){
        int x;
        scanf("%d",&x);
        factor(x);
        int sz = 0;
        int ans = 0;
        int id = 0;
        bool found = 0;
        int ansr = 1e9;
        int idr = 1e9;
        for (int i = 0; i < (int)f.size(); ++i){
            int cur = 1;
            for (int j = i; j < (int)f.size(); ++j){
                cur *= f[j];
                if(vis[cur].first.first != 1e9  and vis[cur].second.first != x){
                    found = 1;
                    if(j - i + 1 > sz){
                        sz = j - i + 1;
                        id = vis[cur].second.second;
                      int mv1 = vis[cur].first.first;
                      int mv2 = f.size() - (j - i + 1);
                      ans = mv1 + mv2;
                    }
                    if(j - i + 1 == sz and vis[cur].second.second <= id){
                        id = vis[cur].second.second;
                      int mv1 = vis[cur].first.first;
                      int mv2 = f.size() - (j - i + 1);
                      ans = mv1 + mv2;
                    }
                    if(ans <= ansr){
                        idr = id;
                        ansr = ans;
                    }

                }
            }
        }
        if(!found){
            idr = 0;
            if(v[0].second.second == x) idr = 1;
            int a = v[idr].second.second;
            int b = x;
            int g = __gcd(a,b);
            a /= g;
            b /= g;
            factor(a);
            int mv1 = f.size();
            factor(b);
            int mv2 = f.size();
            idr = v[idr].second.first;
            ansr = mv1 + mv2;
        }
        printf("%d %d\n", idr + 1, ansr);
    }
	return 0;
}

