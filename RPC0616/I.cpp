#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
  vector<string> V;
  vector<string> V1;
  vector<string> V2;
  vector<string> V3;
  char M[100][100];
  string enc;
  cin>>n;
  m=n;
  int c=0;
  bool res=true;
  string ans="";
  for(int i=0; i<n;i++) 
    for(int j=0; j<n; j++)
      M[i][j]='*';
  for(int i=0; i<n; i++) {
    string s;
    cin>>s;
    V.push_back(s);
  }
  cin>>enc;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(V[i][j]=='.') {
	if(M[i][j]!='*') {
	  res=false;
	}else {
	  M[i][j]=enc[c];
	  c++;
	}
      }
    }
  }
  for(int i=0; i<n; i++) {
    string aux="";
    for(int j=m-1; j>=0; j--) {
      aux+=V[j][i];      
    }
    V1.push_back(aux);
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(V1[i][j]=='.') {
	if(M[i][j]!='*') {
	  res=false;
	}else {
	M[i][j]=enc[c];
	c++;
	}
      }
    }
  }
  for(int i=0; i<n; i++) {
    string aux="";
    for(int j=m-1; j>=0; j--) {
      aux+=V1[j][i];
    }
    V2.push_back(aux);
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(V2[i][j]=='.') {
	if(M[i][j]!='*') {
	  res=false;
	}else {
	M[i][j]=enc[c];
	c++;
	}
      }
    }
  }
  for(int i=0; i<n; i++) {
    string aux="";
    for(int j=m-1; j>=0; j--) {
      aux+=V2[j][i];   
    }
    V3.push_back(aux);
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(V3[i][j]=='.') {
	if(M[i][j]!='*') {
	  res=false;
	}else {
	  M[i][j]=enc[c];
	  c++;
	}
      }
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n;j++) {
      if(M[i][j]=='*') {
	res=false;
      }else {
	ans=ans+M[i][j];
      }
    }
  }
  if(res) {
    cout<<ans<<endl;
  }else {
    cout<<"invalid grille"<<endl;
  }  
  return 0;
}
