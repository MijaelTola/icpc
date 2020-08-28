#include <bits/stdc++.h>
using namespace std;
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int main() {
  int n,m;
  cin>>n>>m;
  char M[110][110];
  int us[110][110];
  memset(M, '0', sizeof M);
  memset(us, 0, sizeof us);
  vector<pair<int, int> > V;
  for(int i=0; i<n; i++) {
    V.push_back(make_pair(0,i));
    V.push_back(make_pair(i,0));
    V.push_back(make_pair(n+1,i));
    V.push_back(make_pair(i,n+1));
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin>>M[i][j];
      if(M[i][j]=='.')
	{
	  M[i][j]='0';
	V.push_back(make_pair(i,j));
	}
    }
  }
  int VIS[110][110];
  for(int i=0; i<V.size();i++) {
    if(us[V[i].first][V[i].second]==0)
      {
	queue<pair<int,int> >q;
	q.push(make_pair(V[i].first,V[i].second));
	us[V[i].first][V[i].second]=1;
	while(!q.empty())
	  {
	    int y=q.front().first;
	    int x=q.front().second;
	    q.pop();
	    for(int p=0;p<4;p++)
	      {
		int k=y+dy[p];
		int l=x+dx[p];
		if(k>=0&&l>=0&&k<n+2&&k<m+2)
		  {
		    if(us[k][l]==0&&M[k][l]=='.')
		      {
			q.push(make_pair(k,l));
			us[k][l]=1;
		      }
		    if(M[k][l]=='T')
		      {
			M[k][l]='1';
			V.push(make_pair(k,l));
		      }
		  }
	      }
	  }
	aux=
	for(int i=0; i<n+2; i++) {
	  for(int j=0; j<=m+2; j++) {
	    cout<<M[i][j];
	  }
	  cout<<endl;
	}
      }
    return 0;
  }
}
