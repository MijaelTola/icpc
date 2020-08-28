#include <iostream>
#include <climits>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vi;
#define MAX INT_MAX;

int n,m,t;
char maze[100][100];
int visited[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
ii beg, endx;

int main(){
	ios:: sync_with_stdio(false); cin.tie();
 	cin >> t;
 	int k = 1;
 	while(t--){	
 	memset(visited,-1,sizeof visited);
 	memset(maze,'\0',sizeof maze);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)	
			cin >> maze[i][j];	
	cin >> beg.first >> beg.second;
	cin >> endx.first >> endx.second;
	visited[beg.first][beg.second] = 0;
	deque<ii> q;
	q.push_front(beg);
	int c = 0;
	ii u;
		while(!q.empty()){
			u = q.front(); q.pop_front();
			if(u.first == endx.first && u.second == endx.second) break;
			for (int i = 0; i < 4; ++i)
			{
				int x = u.first + dx[i];
				int y = u.second + dy[i];
				if(x >= 0 && x <= m && y>=0 && y <= n){
					if(visited[x][y] == -1){
						if(maze[x][y] == '.'){
						q.push_front(ii(x,y));
						visited[x][y] = visited[u.first][u.second];
						}else{
						q.push_back(ii(x,y));
						visited[x][y] = visited[u.first][u.second]+1;
					}
				}	
			}}
		}
		cout << "Laberinto #"<<k<<": "<< visited[endx.first][endx.second] << endl;
	k++;
}
	return 0;
}


