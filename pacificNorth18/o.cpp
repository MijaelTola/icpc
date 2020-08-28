#include <bits/stdc++.h>

using namespace std;
vector<string> mat;
int n;

bool checkAlpha(vector<char> v){
	vector<int> alpha(255,0);
	for(int i = 0; i < v.size(); i++){
		//cout<<v[i]<<" ";
		alpha[v[i]]++;
	}
	//cout<<": ";
	int cnt = 0;
	for(int i = 0; i < 255; i++){
		cnt += alpha[i];
		if(alpha[i] >= 2)
			cnt += 10000;
	}
	//cout<<cnt<<endl;
	return cnt == n;
}

bool LatinSquare(){
	//filas
	bool filas = true;
	for(int i = 0; i < n; i++){
		vector<char> v;
		for(int j = 0; j < n; j++){
			v.push_back(mat[i][j]);
		}
		filas = filas & checkAlpha(v);
	}
	bool columnas = true;
	for(int col = 0; col < n; col++){
		vector<char> v;
		for(int fil = 0; fil < n; fil++){
			v.push_back(mat[fil][col]);
		}
		columnas = columnas & checkAlpha(v);
	}
	return (filas & columnas);
}

bool Reduced(){
	bool ret = true;
	for(int i = 1; i < n; i++){
		if(mat[0][i - 1] >= mat[0][i])
			ret = false;
		if(mat[i - 1][0] >= mat[i][0])
			ret = false;
	}
	return ret;
}

int main(){
	while(cin>>n){
	mat.clear();
	string s;		
	for(int i = 0; i < n; i++){
		cin>>s;
		mat.push_back(s);
	}
	bool latin = LatinSquare();
	bool reduced = Reduced();
	if(latin and reduced)
		cout<<"Reduced"<<endl;
	else
		if(latin)
			cout<<"Not Reduced"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
