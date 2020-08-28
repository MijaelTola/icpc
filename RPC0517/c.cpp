#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<(x)<<'\n';

using namespace std;

int n, m;
int a[2010][2010];

bool can(int x, int y){
	if(x < 0 or x >= n or y < 0 or y >= m) return 0;
	return 1;
}

int check(int x, int y){
	//debug(x);
	//debug(y);
	bool par = 0, impar = 0;
	if(can(x+1,y-1) ){
		//cout<<"uno"<<endl;
		int xx = a[x+1][y-1];
		if(xx!=0){
			if(xx%2 == 0) par = 1;
			else impar = 1;
		}
	}
	if(can(x+1,y+1) ){
		int xx = a[x+1][y+1];
		//cout<<"dos"<<endl;
		if(xx!=0){
			if(xx%2 == 0) par = 1;
			else impar = 1;
		}
	}
	if(can(x-1,y-1) ){
		int xx = a[x-1][y-1];
		//cout<<"tres"<<endl;
		if(xx!=0){
			if(xx%2 == 0) par = 1;
			else impar = 1;
		}
	}
	if(can(x-1,y+1) ){
		int xx = a[x-1][y+1];
		//cout<<"cuatro"<<endl;
		if(xx!=0){
			if(xx%2 == 0) par = 1;
			else impar = 1;
		}
	}

	//cout<<"par = "<<par<<endl;
	//cout<<"impar = "<<impar<<endl;

	if(impar and par) return -1;
	if(!impar and !par) return -2;
	return par;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	cin>>n>>m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>a[i][j];
		}
	}

	bool flag = 0;

	if(a[0][0] == 0){
		bool r = check(0,0);
		if(r) a[0][0] = 1;
		else a[0][0] = 2;
	}

	//cout<<check(1,0)<<endl;
	//cout<<can(1-1,0+1)<<endl;

	//return 0;

	for(int i = 1; i < m; i++){
		if(a[0][i] == 0){
			int r = check(0,i);
			if(r != -1){
				if(r == 1){
					int u = a[0][i-1]+1;
					if(u%2 == 0) a[0][i] = u+1;
					else a[0][i] = u;
				}else{
					if(r == -2){
						a[0][i] = a[0][i-1]+1;
					}else{
						int u = a[0][i-1]+1;
						if(u%2 == 0) a[0][i] = u;
						else a[0][i] = u+1;
					}
				}
			}else{
				flag = 1;
				break;
			}
		}
	}

	//for(int i = 0; i < n; i++) cout<<a[0][i]<<' ';

	if(flag){
		cout<<-1<<'\n';
		return 0;
	}

	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
		    if(a[i][j] == 0){
				int r = check(i,j);
				if(r != -1){
					int u ;
					if(j > 0) u = max(a[i][j-1],a[i-1][j]) + 1;
					else u = a[i-1][j] + 1;
					//cout<<"u = "<<u<<endl;
					//cout<<"r = "<<r<<endl;
					if(r){
						if(u%2 == 0) a[i][j] = u+1;
						else a[i][j] = u;
					}else{
						if(u%2 == 0) a[i][j] = u;
						else a[i][j] = u+1;
					}
				}else{
					flag = 1;
					break;
				}
			}
		}
		if(flag) break;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}

	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] <= a[i-1][j]){
				//cout<<"i = "<<i<<" j = "<<j<<endl;
				flag = 1;
			}
		}
	}

	if(flag){
		cout<<-1<<'\n';
		return 0;
	}

	long long sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			sum = sum + a[i][j];
		}
	}

	cout<<sum<<'\n';

	
	return 0;
}
