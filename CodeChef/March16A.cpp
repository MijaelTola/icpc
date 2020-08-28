#include <bits/stdc++.h>

using namespace std;

int main(){

	string a,b;
	int t;
	cin >> t;
	while(t--){
			cin >> a >> b;
	int v[27];
	memset(v,0,sizeof v);
	for (int i = 0; i < a.size(); ++i)
		v[a[i]-'a']++;
	
	int c = 0;
	for (int i = 0; i < b.size(); ++i)
	{
		if(a[b[i] - 'a'] != 0){
			a[b[i] - 'a']--;
			c++;
		}
	}
	if(c >= 1) cout << "Yes";
	else cout <<"No";
	cout << endl;
}
	return 0;
}