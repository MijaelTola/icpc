#include <bits/stdc++.h>

using namespace std;

pair<int,int> v[105];
int main(){
    int n; cin >> n;
    int pos = 0;    
    for (int i = 0; i < n; ++i){
        int a,c; cin >> a >> c;
        v[pos].first = a;
        v[pos++].second = i;
        int cur = pos - 1;
        while(cur > 0 and c){
            if(abs(v[cur].first  - v[cur - 1].first) == 1 and v[cur].first > v[cur - 1].first) 
                swap(v[cur],v[cur - 1]), cur--;
            else break;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << v[i].second + 1<< " ";
    cout << "\n";
    return 0;
}

