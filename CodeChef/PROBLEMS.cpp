#include <bits/stdc++.h>

using namespace std;

pair<int,int> ds[30];
vector<pair<int,int> > v;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int p,s;
    cin >> p >> s;

    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < s; ++j) 
            cin >> ds[j].first;
        for (int j = 0; j < s; ++j)
            cin >> ds[j].second;
        sort(ds, ds + s);
        int n = 0;
        for (int j = 0; j < s - 1; ++j) {
            if(ds[j].second > ds[j + 1].second)
                n++;
        }
        v.push_back(make_pair(n,i));
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < (int)v.size(); ++i)
        cout <<  v[i].second  + 1<< "\n";
    return 0;
}

