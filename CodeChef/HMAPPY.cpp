#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
int a[100010];
int b[100010];
priority_queue<pair<long long,int> > q;
int main() {
    scanf("%d %lld", &n, &m);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);
    
    for (int i = 0; i < n; ++i) 
        q.push(make_pair(a[i]*b[i],i));
    
    while(true) {
        long long candies = q.top().first;
        int id = q.top().second;
    }
    return 0;
}

