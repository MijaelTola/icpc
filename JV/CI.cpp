#include <bits/stdc++.h>

using namespace std;

struct compare
{
	bool operator() (const pair<int, int> a, const pair<int,int> b){
		if(a.second == b.second) return a.first > b.first;
		else return a.second < b.second;
	}
};
int main(){

	int n;
	priority_queue<pair<int,int>, vector<pair<int,int> >, compare > q;
	cin >> n;
	string x;
	int v[27];
	for (int i = 0; i < 27; ++i) v[i] = 0;
	cin.ignore();
	while(n--){
		getline(cin,x);
		for (int i = 0; i < x.size(); ++i)
		{
			if(x[i] == ' ') continue;
			v[x[i]-'a']++;
		}
	}
	for (int i = 0; i < 27; ++i)
		if(v[i] != 0) q.push(make_pair(i,v[i]));	
	
	while(!q.empty()){
		char a = q.top().first + 'a';
		cout << a << " " << q.top().second << endl;
		q.pop();
	}
	return 0;
}