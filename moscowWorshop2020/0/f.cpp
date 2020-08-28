#include <bits/stdc++.h>

using namespace std;

const long long md1 = 1e9 + 7;
const long long md2 = 1e9 + 9;
const long long B = 12150;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

pair <long long, long long> _hash(vector <long long> x) {
  long long h1 ,h2;
  h1 = h2 = 0;
  for (int i = 0; i < x.size(); i++) {
    h1 = (h1 * B + x[i]) % md1;
    h2 = (h2 * B + x[i]) % md2;
  }
  return {h1, h2};
}

int main() {
  int n, m, c;
  scanf("%d %d %d", &n, &m, &c);
  vector < pair <long long , long long> > temp;
  for (int i = 0; i < n; i++) {
    vector <long long> x(c);
    for (int j = 0; j < m; j++) {
      int z; scanf("%d", &z);
      x[z - 1]++;
    }
    temp.push_back(_hash(x));
  }
  vector <pair <long long, long long> > r;
  for ( int ni = 1; ni <= n; ni++) {
    vector <long long> temp2(c, (1LL * ni * m) / c);
    //for (int x : temp2) cerr << x << ' '; cerr << endl;
    r.push_back(_hash(temp2));
  }
  //sort(r.begin(), r.end());
  //cerr << "r: " << endl;for (auto res : r) cerr << res.first << ' ' << res.second << endl;
  if (n == 1) {
    printf("%d\n", temp[0] == r[0]);
  }
  else {
    int ans = 0;
    vector <pair <long long, long long> > L, R;
    unordered_map<pair<long long, long long>, bool, hash_pair> L2;
    int nL = n / 2;
    int nR = n - nL;
    //cerr << nL << ' ' << nR << endl;
    for (int msk = 0; msk < (1 << nL); msk++) {
      pair <long long, long long> tot = {0, 0};
      for (int i = 0; i < nL; i++) {
        if ((msk >> i) & 1) {
          tot = {(tot.first + temp[i].first) % md1, (tot.second + temp[i].second) % md2};
        }
      }
      L.push_back(tot);
      L2[tot] = 1;
    }
    sort(L.begin(), L.end());
    //cerr << "L: " << endl;for (auto res : L) cerr << res.first << ' ' << res.second << endl;cerr << endl;
    //cerr << L.size() << endl;
    for (int msk = 0; msk < (1 << nR); msk++) {
      pair <long long, long long> tot = {0, 0};
      for (int i = 0; i < nR; i++) {
        if ((msk >> i) & 1) {
          tot = {(tot.first + temp[i+nL].first) % md1, (tot.second + temp[i+nL].second) % md2};
        }
      }
      //R.push_back({tot, __builtin_popcount(msk)});
      //cerr << L[0].first << endl;
      //cerr << msk << endl;
      for (int i = 0; i < r.size(); i++) {
        pair <long long, long long> res = r[i];
        pair <long long, long long> s = {((res.first - tot.first) % md1 + md1) % md1, ((res.second - tot.second) % md2  + md2) % md2};
        //cerr << "s: "<< s.first << ' ' << s.second << endl;
        //auto pp = lower_bound(L.begin(), L.end(), s);
        //if (pp != L.end())cout << "pp: " << pp->first << ' ' << pp->second << endl;
        //if (pp != L.end() && *pp == s) ans = max(ans, i + 1);
        //if (ans == 3) {cout << "ssss" << endl; break;}
        if(L2[s]) ans = max(ans, i + 1);
      }
    }
    //cerr << R.size() << endl;
    /*
    for (int i = 0; i < r.size(); i++) for (auto LL: L) for (auto RR: R) {
      pair<long long, long long> tot = {(LL.first + RR.first) % md1, (LL.second + RR.second) % md2};
      //cerr << tot.first << ' ' << tot.second << endl;;
      if (r[i] == tot) {
        ans = max(ans,  i + 1);
      }
    } */
    printf("%d\n", ans);
  }
  return 0;
}

