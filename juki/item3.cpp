#include <bits/stdc++.h>
using namespace std;
typedef short Long;

const Long MX = 1000;

vector<Long> Q[2][MX];
Long vis[MX];
bool basic[MX];
bool child[2][MX][MX];
Long parent;

void dfs(Long u, Long t, Long xx){
	vis[u] = xx;
	for(Long v : Q[t][u]){
		if(vis[v] != xx) dfs(v,t,xx);
	}
	if(t == 0){
		child[0][parent][u] = true;
	}else{
		if(basic[u]) child[1][parent][u] = true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(10);
	cout << fixed;
	
	string s;
	Long n;
	cin >> n;
	getline(cin,s);
	
	vector<string> item;
	map<string,Long> conv;
	
	for(Long i = 0; i < n; i++){
		getline(cin,s);	
		item.push_back(s);
	}
	sort(item.begin(),item.end());
	for(Long i = 0; i < n; i++) conv[item[i]] = i;

	
	Long m, cn;
	cin >> m;
	string ini;
	for(Long i = 0; i < m; i++){
		cin >> cn;
		getline(cin,ini);
		getline(cin,ini);
		Long u = conv[ini];
		for(Long j = 0; j < cn; j++){
			getline(cin,s);
			Long v = conv[s];
			//cout << "===> " << u << " " << v << endl;
			Q[1][u].push_back(v);
			Q[0][v].push_back(u);
		}
	}
	
	for(Long i = 0; i < n; i++){
		if(Q[1][i].empty()) basic[i] = true;
	}
	
	
	for(Long i = 0; i < n; i++){
		parent = i;
		dfs(i,0,i*2);
		dfs(i,1,i*2+1);
		child[0][i][i] = child[1][i][i] = false;
	}
	
	
	Long que, t;
	cin >> que;
	for(Long i = 0; i < que; i++){
		
		if(i != 0) cout << "\n";
		
		cin >> t;
		t--;
		getline(cin,s);
		getline(cin,s);
		//cout << "--> \n";
		if(conv.find(s) == conv.end()){
			cout << "None\n";
			cout << "\n";
			continue;
		}
		Long u = conv[s];
		Long con = 0;
		
		for(Long j = 0; j < n; j++){
			if(child[t][u][j]){
				cout << item[j] << "\n";
				con++;
			}
		}
		if(con == 0) cout << "None\n";
	}
	return 0;
}
