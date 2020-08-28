#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;cin >>n  >> k;
  string str;
  cin >> str;
  vector < int > ans[n / (k + 1)];
  vector <int> lastb(n, -1), nextb(n, -1);
  int cur = -1;
  for (int i = 0; i < n; i++) {
    lastb[i] = cur;        
    if (str[i] == 'w') cur = i;
  }
  cur = n;
  for (int i = n - 1; i >= 0; i--) {
    nextb[i] = cur;        
    if (str[i] == 'w') cur = i;
  }
  set < tuple <int, int, int, int> > s1, s2;
  set < pair <int, char> > s3;
  for (int i = 0; i < n; i++) {
    s3.insert({i, str[i]});
    if (str[i] == 'w') {
      int len1 = i - lastb[i] - 1;
      int len2 = nextb[i] - i - 1;
      s1.insert({len1 + len2, i, len1, len2});
      s2.insert({i, len1 + len2, len1, len2});
    }
  }
  int z = n / (k + 1);
  for (int zz = 0; zz < z; zz++) {
   
    /*    cerr << "s2" << endl;for (auto xx : s3) {
      cerr << xx.first << ' ' << xx.second << " $$$ ";
    }*/
   /* cerr <<endl;
      cerr << "s3" << endl;for (auto xx : s3) {
      cerr << xx.first << ' ' << xx.second << " $$$ ";
    }
    cerr <<endl;
    */
    auto it = (--s1.end());
    int tot, len1, len2, i;
    tie(tot, i, len1, len2) = *it;
    auto itC = s2.lower_bound({i, tot, len1, len2});
    auto itL = itC, itR = itC;
    itL--;
    itR++;
    tuple <int, int, int, int> nL, nR, oldL = *itL, oldR = *itR;
    if (itL != s2.end()) {
      int totL, len1L, len2L, iL;
      tie(iL, totL, len1L, len2L) = oldL;
      nL = {iL, len1L + tot - k, len1L, tot - k};
    }
    if (itR != s2.end()) {
      int totL, len1L, len2L, iL;
      tie(iL, totL, len1L, len2L) = oldR;
      nR = {iL, len1L + tot - k, len1L, tot - k};
    }
    auto itZ = s3.lower_bound({i, 0});
    vector <int> index;
    if (len1 >= k) {
      for (int yy = 0; yy <= k;yy++) {
        index.push_back((*itZ).first);
        itZ--;
      }
    } else if (len2 >= k) {
      for (int yy = 0; yy <= k;yy++) {
        index.push_back((*itZ).first);
        itZ++;
      }
    } else {
      auto itZZ = itZ;
      for (int yy = 0; yy <= len1;yy++) {
        index.push_back((*itZZ).first);
        itZZ--;
      }
      for (int yy = 0; yy < k - len1;yy++) {
        itZ++;
        index.push_back((*itZ).first);        
      }
    }
    for (int j : index) s3.erase({j, str[j]}), ans[zz].push_back(j + 1);

    s1.erase({tot, i, len1, len2});
    s1.erase({get<1>(oldL),get<0>(oldL),get<2>(oldL),get<3>(oldL) });
    s1.erase({get<1>(oldR),get<0>(oldR),get<2>(oldR),get<3>(oldR) });
    s1.insert({get<1>(nR),get<0>(nR),get<2>(nR),get<3>(nR)});
    s1.insert({get<1>(nL),get<0>(nL),get<2>(nL),get<3>(nL)});
    
    s2.erase({i, tot, len1, len2});
    s2.erase(oldL);
    s2.erase(oldR);
    s2.insert(nL);
    s2.insert(nR);
  }
  for (int i = z - 1; i >= 0; i--) {
    for (int p : ans[i]) cout << p << ' ';
    cout << '\n';
  }
  return 0;
}
