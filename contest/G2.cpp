#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	for(int cs=0;cs<n;cs++)
	{
		long long a,b,c,a1,b1,c1;
		cin>>a>>b>>c>>a1>>b1>>c1;
		int sol=0;
		int sol1=0;
		if(a+b+c>a1+b1+c1)
		{
			sol1++;
		}
		if(a>a1)
		{
			sol++;
		}
		else
		{
			if(a==a1)
			{
				if(b>b1)
				{
					sol++;
				}
				else
				{
					if(b==b1)
					{
						if(c>c1)sol++;
					}
				}
			}
		}
		cout<<a<<b<<c<<a1<<b1<<c1<<endl;
		if(sol==0&&sol1==0)
		{
			cout<<"none"<<endl;
			continue;
		}
		if(sol==1&&sol1==0)
		{
			cout<<"color"<<endl;
			continue;
		}
		if(sol==0&&sol1==1)
		{
			cout<<"count"<<endl;
			continue;
		}
		if(sol==1&&sol1==1)
		{
			cout<<"both"<<endl;
			continue;
		}
	}
}
