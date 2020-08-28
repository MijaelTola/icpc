#include <bits/stdc++.h>

using namespace std;

// size 2*n-1
const int NEUTRO = 0;
int mem[3000][3000];
int n;
int inf=100000000;

// interval[l,r)
int query(int l,int r){
	if(mem[][])
}

int v[2010];
int main(){
    
    while(scanf("%d", &n) != EOF) {
        memset(mem,0,sizeof mem);
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            v[i] = x;
            update(i,max(0,x));
            sol ^= x;
        }
        
        for (int i = 0; i < n; ++i) 
            for (int j = i + 1; j < n; ++j) 
                sol ^= query(i,j);

        printf("%d\n",sol);           
    }

	return 0;
}

