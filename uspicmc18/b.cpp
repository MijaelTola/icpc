#include <bits/stdc++.h>
 
using namespace std;
 
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

char cad[500010];

int main(){
	int n = in();
	scanf("%s", cad);
	for (int i = 1; i < n;i++) {
		if (cad[i] < cad[0])  {
			return puts("No"),0;
		}
	}
    
	puts("Yes");
	return 0;
}

