#include <iostream>
#include <vector>

using namespace std;

vector<int> G[110];
char type[110];
void print(int u,bool exp, string space){
	if(exp){
	for (auto i: G[u]){
		cout << space;
		if(G[i].size() > 0) cout << type[i] << " ";
		else cout << "  ";
		cout << "object"<<i<<"\n";
		if(type[i] == '-') exp = true;
		else exp = false;
		print(i,exp,space+"  ");
	}
	}
}
int main(){
	int n; cin >> n;
	for (int i = 0; i < n+1; ++i){
		char s;
		int k;
		cin >> s >> k;
		type[i] = s;
		for (int j = 0; j < k; ++j){
			int x; cin >> x;
			G[i].push_back(x);
		}
	}
	if(G[0].size() == 0) cout << "  project\n";
	else if(type[0] == '-'){
		cout << "- project\n";
		print(0,true,"  "); 
	}else{
		cout << "+ project\n";
	}
	return 0;
}
