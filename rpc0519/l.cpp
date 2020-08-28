#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main() {
    int n,c;
    cin >> n >> c;

    for (int i = 0; i < c; ++i)
        cin >> v[i];

    priority_queue<pair<int,int> > q;

    for (int i = 1; i <= n; ++i) 
        q.push({0, -i});
    
    for (int i = 0; i < c; ++i) {
        cout << -q.top().second;
        if(i + 1 < c) cout << " ";
        int cost = -q.top().first;
        int id = q.top().second;
        q.pop();
        cost += v[i];
        q.push({-cost, id});

    }
    cout << "\n";
    return 0;
}

