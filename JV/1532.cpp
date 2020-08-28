#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long n;
    while(scanf("%lld",&n) != EOF){
        vector<int> s;
        while(n > 0){
            int m = n % 10;
            n /= 10;
            s.push_back(m);
        }
        sort(s.begin(),s.end());
        for (int i = 0; i < (int)s.size(); ++i){
            printf("%d",s[i]);
        }
        puts("");
    }
    return 0;
}

