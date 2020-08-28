#include <bits/stdc++.h>

using namespace std;

int v[100010];
int a[100010];
int main(){
    int n;
    while(cin >> n and n){
        memset(a,0,sizeof a);
        memset(v,0,sizeof v);
        for (int i = 0; i < n; ++i) cin >> v[i];
        
        for (int i = n - 1; i >= 0; --i)
            a[i] = v[i] + a[i + 1];
    
        bool f = 0;
        int id = -1;
        for (int i = 0; i < n; ++i){
            if(v[i] >= a[i + 1] and i + 1 < n)
            {f = 1; id = i; break;}
        }

        if(!f) puts("NO");
        else cout << "SI" << " " << id + 1 << "\n";
    }
    return 0;
}

