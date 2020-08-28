#include <iostream>
#include <cstring>
#include <cassert>
#include <queue>

using namespace std;


int dxC[]=   {1,1,2,2,-1,-1,-2,-2};
int dyC[]=   {2,-2,1,-1,2,-2,1,-1};

int dxA[] = {1,1,-1,-1};
int dyA[] = {1,-1,-1,1};

int n,m;

char c[550][550];
bool visC[550][550];
bool visA[550][550];
bool mark[550][550];

queue<pair<pair<int,int>,bool> > q;

void clean(){
	for (int i = 0; i < 550; ++i)
		for (int j = 0; j < 550; ++j){
			visA[i][j] = false;
			visC[i][j] = false;
			mark[i][j] = false;
		}
}
void moveC(int x,int y){
	for (int i = 0; i < 8; ++i){
		int u = x + dxC[i];
		int v = y + dyC[i];
		if(u >= 0 and u < n and v >= 0 and v < m and !visC[u][v] and c[u][v] != 'T'){
			visC[u][v] = true;
			q.push({{u,v},true});
		}
	}
}

void moveA(int x, int y){
	for (int i = 0; i < 4; ++i){
		int u = x + dxA[i];
                int v = y + dyA[i];
                if(u >= 0 and u < n and v >= 0 and v < m and !visA[u][v] and c[u][v] != 'T'){
			visA[u][v] = true;
			q.push({{u,v},false});
                }

	}
}
int main(){
	int k = 0;
	while(cin >> n >> m and n and m){
		clean();
		assert(n>=1&&n<=500 && m>=1&& m<=500);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j){
				cin >> c[i][j];
				//assert(isdigit(c[i][j]) or c[i][j] == 'T' or c[i][j] == 'B' or c[i][j] == '.' or c[i][j] =='K');
				if(c[i][j] == 'K') q.push({{i,j},true});
				if(c[i][j] == 'B') q.push({{i,j},false});
			}
		
		int ans = 0;
		while(!q.empty()){
			int x = q.front().first.first;
			int y = q.front().first.second;
			bool type = q.front().second;
			q.pop();
			if(isdigit(c[x][y]))  mark[x][y] = true;
			if(type) moveC(x,y);
			else moveA(x,y);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j){
				if(isdigit(c[i][j]) and mark[i][j])
					ans += (int)(c[i][j] - '0');
			}
		cout << "Caso #" << ++k<< ": "<< ans << "\n";
	}
	return 0;
}
