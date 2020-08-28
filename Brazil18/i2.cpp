#include <bits/stdc++.h>

using namespace std;
vector<int> v[1005];
set<string> cad;
int main(){
	int ns,nf,tmp,aux;
	scanf("%d %d", &ns, &nf);
	scanf("%d",&tmp);
	string s(nf,'0');
	for(int i = 0; i < tmp; i++){
		scanf("%d",&aux);
		aux--;
		s[aux] = '1';
	}
	for(int i = 0; i < ns; i++){
		scanf("%d",&tmp);
		for(int j = 0; j < tmp; j++){
			scanf("%d",&aux);
			aux--;
			v[i].push_back(aux);
		}
	}
	bool sw = false;
	int cnt = 0;int ans = 0;
	string res(nf,'0');

	while(!sw){
		//cout<<s<<endl;
		if(cad.count(s) != 0){
			ans = -1;
			break;
		}
		if(ans >= 10000){
			ans = -1;
			break;
		}
		if(res == s){
			break;
		}
		//cad.insert(s);
		for(int i = 0; i < v[cnt].size(); i++){
			int foco = v[cnt][i];
			s[foco] = (s[foco] == '1'? '0':'1');
		}
		ans++;
		cnt++;
		cnt = cnt % ns;
	}
	printf("%d\n",ans);
	return 0;
}
