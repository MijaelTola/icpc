#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin>>T;
  vector<pair<string,pair<long long, long long>>> V;
  while(T--) {
    V.clear();
    long long mend=1, menn=1;
    long long mend2=1, menn2=1;
    string s;
    long long k, d;
    for(int i=0; i<5; i++) {
      cin>>s>>k>>d;
      if(d==0) k=1000000001;
      int g=__gcd(k,d);
      V.push_back(make_pair(s,make_pair(k/g,d/g)));
      if(k*mend<d*menn) {
	mend=d;
	menn=k;
      }
    }
    for(int i=0; i<5; i++) {
      cin>>s>>k>>d;
      if(d==0) k=1000000001;
      int gcd1=__gcd(k,d);
      V.push_back(make_pair(s,make_pair(k/gcd1,d/gcd1)));
      if(k*mend2<d*menn2) {
	mend2=d;
	menn2=k;
      }
    }
    for(int i=0; i<V.size(); i++) {
      if(i<5) {
	k=V[i].second.first;
	d=V[i].second.second;
	s=V[i].first;
	if(mend==d && menn==k) {
	  cout<<s<<" plz uninstall\n";
	}else {
	  k*=3;
	  if(k<d) {
	    cout<<s<<" plz uninstall\n";
	  }
	}
      }else {
	k=V[i].second.first;
	d=V[i].second.second;
	s=V[i].first;
	if(mend2==d && menn2==k) {
	  cout<<s<<" plz uninstall\n";
	}else {
	  k*=2;
	  
	  if(k<d) {
	    cout<<s<<" plz uninstall\n";
	  }
	}
      }
    }
  }
  return 0;
}
