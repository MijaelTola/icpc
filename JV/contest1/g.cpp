#include <bits/stdc++.h>

using namespace std;

int v[100010];
int b[3];
int t[3];
int main() {
    int x,y,z,n;
    cin >> x >> y >> z >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    priority_queue<pair<long long, pair<long long, long long> > > q;
    q.push({0, {-0, x}});
    q.push({0, {-1, y}});
    q.push({0, {-2, z}});
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long time = -q.top().first;
        long long dis = -q.top().second.first;
        long long total = q.top().second.second;
        q.pop();
        if(total < v[i]) {
            long long time1 = -q.top().first;
            long long dis1 = -q.top().second.first;
            long long total1 = q.top().second.second;
            q.pop();
            if(total1 < v[i]) {
                long long time2 = -q.top().first;
                long long dis2 = -q.top().second.first;
                long long total2 = q.top().second.second;
                q.pop();
                if(total2 < v[i]) return cout << "-1\n",0;
                time2 += v[i];
                total2 -= v[i];
                if(i + 1 < n) 
                    ans = max(ans, time2);
                q.push({-time2,{-dis2, total2}});
                q.push({-time1,{-dis1, total1}});
                q.push({-time,{-dis, total}});
                continue;
            }
            time1 += v[i];
            total1 -= v[i];
            if(i + 1 < n) 
                ans = max(ans, time1);
            q.push({-time1,{-dis1, total1}});
            q.push({-time,{-dis, total}});
            continue;
        }
        time += v[i];
        total -= v[i];
        q.push({-time,{-dis, total}});
        if(i + 1 < n) 
            ans = max(ans, time);
    }
    cout << ans << "\n";
    return 0;
}
