#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>

using namespace std;

struct SuffixArray{
    int order[2*100010];
    int cpyorder[2*100010];
    int count[2*100010];
    int class1[2*100010];
    int class2[2*100010];
    string s;
    int sz;
    void sortcharacter(){
        for (int i = 0; i < sz; ++i)
            count[s[i]-'A'+1]++;
        count[0] = 1;
        for (int i = 1; i < 28; ++i)
            count[i] += count[i-1];
        for (int i = sz; i >= 0; --i){
            int c = s[i]-'A'+1;
            if(s[i] == '$') c = 0;
            count[c]--;
            order[count[c]] = i;
        }
    }
    void ComputeCharClasses(){
        class1[order[0]] = 0;
        for (int i = 1; i < sz; ++i){
            if(s[order[i]]!=s[order[i-1]])
                class1[order[i]] = class1[order[i-1]]+1;
            else class1[order[i]] = class1[order[i-1]];
        }
    }
    
    void SortDoubled(int l){
        memset(count,0,sizeof count);
        for (int i = 0; i < sz; ++i)
            cpyorder[i] = order[i];
        for (int i = 0; i < sz; ++i)
            count[class1[i]]++;
        for (int i = 1; i < sz; ++i)
            count[i] += count[i-1];
        for (int i = sz-1; i >= 0; --i){
            int start = (cpyorder[i] - l + sz)%sz;
            int cl = class1[start];
            count[cl]--;
            order[count[cl]] = start;
        }
    }

    void updateClasses(int l){
        for (int i = 0; i < sz; ++i)
            class2[i] = class1[i];
        class1[order[0]] = 0;
        for (int i = 1; i < sz; ++i){
            int cur = order[i];
            int prev = order[i-1];
            int mid = (cur+l)%sz;
            int midp = (prev+l)%sz;
            if(class2[cur] != class2[prev] or class2[mid] != class2[midp])
                class1[cur] = class1[prev]+1;
            else class1[cur] = class1[prev];
        }
    }
    
    SuffixArray(string x){
        s = x;
        sz = s.size();
        sortcharacter();
        ComputeCharClasses();
        int l = 1;
        while(l < sz){
            SortDoubled(l);
            updateClasses(l);
            l *= 2;
        }
    }
};
int main(){
    string x; cin >> x;
    SuffixArray SA(x);
    for (int i = 0; i < (int)x.size(); ++i)
        cout << SA.order[i] << " ";
    return 0;
}

