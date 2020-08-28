#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char ma[2000][2000];
char ma1[2000][2000];
char sol[2000][2000];
vector<pair<int,int> > v;
int main()
{
	ios::sync_with_stdio(0);
	int n,m;
	string fal;
	while(cin>>n>>m>>fal)
	{
		if(n==0)break;
		char al=fal[1];
		int fx,fy,fx1,fy1;
		bool first=true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				{
					cin>>ma[i][j];
					sol[i][j]=ma[i][j];
					if(ma[i][j]==al&&first)
					{
						fy=i;fx=j;
						first=false;
					}
				}
		}
		first=true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				{
					cin>>ma1[i][j];
					if(ma1[i][j]==al&&first)
					{
						fy1=i;fx1=j;
						first=false;
					}
					if(ma[i][j]==al)
					{
						sol[i][j]=ma1[i][j];
					}
					if(ma1[i][j]==al)
					{
						v.push_back(make_pair(i,j));
					}
				}
		}
		int dify=-1*(fy-fy1);
		int difx=-1*(fx-fx1);
		//cout<<dify<<" "<<difx<<endl;
		for(int i=0;i<v.size();i++)
		{
			int k=v[i].first+dify;
			int l=v[i].second+difx;
			if(k>=0&&l>=0&&k<n&&l<m)
			{
				sol[k][l]=al;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				{
					cout<<sol[i][j];
				}
				cout<<"\n";
		}
		cout<<"\n";
		v.clear();
	}
}