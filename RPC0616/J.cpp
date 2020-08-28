#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while(cin>>n) {
    int x;
    int MAXN= -1;
    for(int i=0; i<n; i++) {
      cin>>x;
      MAXN=max(MAXN, x);
    }
    string s;
    stringstream ss;
    ss<<MAXN;
    ss>>s;
    cout<<"0."<<s;
    if(s.length()==1) {
      cout<<"0000"<<endl;
    }else {
      cout<<"000"<<endl;
    }
  }
  return 0;
}
