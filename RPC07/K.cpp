#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	ll sum=0;

	for(ll i=1;i>0;i++)
	{
		cin>>n;
		if(n==0)break;
		sum+=n;
		ll mon=sum/50;
		if(mon!=0)
		{
			if(mon==1)
			{
				cout<<"Input #"<<i<<": Sweet!\n";
				sum=sum-(50*mon);
			}
			else
			{
				cout<<"Input #"<<i<<": Totally Sweet!\n";
				sum=sum-(50*mon);
			}
		}
	}
}
