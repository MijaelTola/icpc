#include <bits/stdc++.h>

using namespace std;
bool Primes[1000010];
int v[100010];
vector<int>P;

vector<int>fact(int n) {
	vector<int>ans;
	int PF = P[0], pos = 0;
	while (PF * PF <= n && pos < (int)P.size()) {
		if (n % PF == 0) {
			ans.push_back(PF);
			while(n % PF == 0) {
				n /= PF;
			}
		}
		PF = P[pos++];
	}
	if (n != 1)ans.push_back(n);
	return ans;
}

struct node{
    map<int,node*> t;
    bool end;
    int val;
    node(){end = false;}
};

struct trie{
    node* root;
    trie(){root = new node();}
    void insert(vector<int> &pattern, int val){
        node* copy = root;
        for (int v: pattern){
			if(copy->t[v] == NULL)
                copy->t[v] = new node();
            copy = copy->t[v];
        }
        copy->end = true;
        copy->val = val;
    }

    pair<bool,int> find(vector<int> &pattern){
        node* copy = root;
        int ans = 1e9;
        bool flag = 1;
        for(int v: pattern){
			if(copy->end) ans = min(ans, copy->val);
            if(copy->t[v] == NULL) {
                flag = 0;
                copy->t[v] = new node();
            }
            copy = copy->t[v];
        }
        if(copy->end) ans = min(ans,copy->val);
        else flag = 0;
        return {flag, ans};
   }

    
};

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 2; i * i <= 1000000;i++)
		if (!Primes[i])
			for (int  j = i * i; j <= 1000000;j +=i)Primes[j] = i;
	P.push_back(2);
	for (int i = 3; i <= 1000000;i++)if (!Primes[i])P.push_back(i);
   
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
        bool one = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
            if(v[i] == 1) one = 1;
        }

        if(one) {
            cout << n << "\n";
            continue;
        }
		sort(v, v + n);
		trie T;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			vector<int> facts = fact(v[i]);
			pair<bool,int> p = T.find(facts);
            if(!p.first) T.insert(facts,v[i]);
            if(p.second != 1e9) ans += p.second;
            else ans += v[i];
		}
		
		cout << ans << "\n";
	}
	return 0;
}
