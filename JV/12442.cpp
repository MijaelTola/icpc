#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 50000
typedef vector<int> vi;

int dfs_num[MAX];
vi adjacentList[MAX];

void dfs(int u){
	dfs_num[u] = 0;
	count++;
	for (int i = 0; i < adjacentList[u].size(); ++i)
	{
		int v = adjacentList[u][i];
		if(dfs_num[v] == -1)
			dfs(v);
	}
}
int main(){
	int t,n;

	for (int i = 0; i < MAX; ++i)
	{
		List[i].clear();
	}
	memset(dfs_num,-1,sizeof dfs_num);
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x,y;
		cin >> x >> y;
		adjacentList[x].push_back(y);
	}
	return 0;
}