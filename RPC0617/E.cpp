#include <bits/stdc++.h>

using namespace std;
/*void div(int a, int b, bool dec,bool is){
    if(s.count(a)) return;
    s.insert(a);
    if(a < b){
        a *= 10;
        if(!dec){
            ans << ".";
            dec = true;
        }else if(is) ans << "0";
        is = true;
        div(a,b,dec,is);
    }else{
        int cur = a/b;
        ans << cur;
        a %= b;
        is = false;
        div(a,b,dec,is);
    }
}*/
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    scanf("%d",&t);
    while(t--){
        set<int> s;
        stringstream ans;
        int n;
        scanf("%d",&n);
        int num = 10;
        ans <<"0.";
        s.insert(10);
        bool flag = true;
        while(!s.count(num) or flag){
            flag = false;
            while(num < n){num*=10; ans << "0";}
            int cur = num / n;
            int mod = num % n;
            ans << cur;
            num = mod * 10;
        }
        printf("%s\n",ans.str().c_str());
    }
    return 0;
}

