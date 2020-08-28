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

typedef long long ll;

struct SuffixArray{
    int order[2*100010];
    int cpyorder[2*100010];
    int pos[2*100010];
    int count[2*100010];
    int class1[2*100010];
    int class2[2*100010];
    int lcp[2*100010];
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
    
    void computeLCP(){
        memset(count,0,sizeof count);
        int i,L;
        pos[order[0]] = -1;
        for(i = 1; i < sz; ++i)
            pos[order[i]] = order[i-1];
        
        for (i = L = 0; i < sz; ++i){
            if(pos[i] == -1){count[i] = 0; continue;}
            while(s[i+L] == s[pos[i]+L]) L++;
            count[i] = L;
            L = max(L-1,0);
        }

        for (i = 0; i < sz; ++i) lcp[i] = count[order[i]];
        for (i = 0; i < sz; ++i) lcp[i] = lcp[i+1];
        lcp[sz] = 0;
    }
    void build(string &x){
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
        computeLCP();
    }
    SuffixArray(){}
};

struct node{
    node* parent;
    map<char,node*> children;
    int depth;
    int start;
    int end;
    node(node* paren, int dp, int st,int ed){
        parent = paren;
        depth = dp;
        start = st;
        end = ed;
    }
    node(){}
};

SuffixArray SA;
struct SuffixTree{
    node* root;
    string s;
    int sz;
    
    void dfs(node* cur){
        if(cur == NULL) return;
        for (pair<char,node*> v: cur->children){
            if(v.second != NULL){
                //cout << v.second->start << " " << v.second->end+1 << endl;
                for(int i = v.second->start; i <= v.second->end; ++i)
                    cout << s[i];
                cout << "\n";
                dfs(v.second);
            }
        }
    }
    node* CreateNewLeaf(node* cur, int suffix){
        node* leaf = new node(cur,sz-suffix,suffix+cur->depth,sz-1);
        cur->children[s[leaf->start]] = leaf;
        return leaf;
    }

    node* BreakEdge(node* cur,int start,int offset){
        char st = s[start];
        char mid = s[start+offset];
        node* nmid = new node(cur,cur->depth+offset,start,start+offset-1);
        cur->children[st]->start += offset;
        nmid->children[mid] = cur->children[st];
        cur->children[st]->parent = nmid;
        cur->children[st] = nmid;
        return nmid;
    }
    void STfromSA(string &x){
        s = x;
        sz = s.size();
        root = new node(NULL,0,-1,-1);
        int lcpPrev = 0;
        node* cur = root;
        for (int i = 0; i < sz; ++i){
            int suffix = SA.order[i];
            while(cur->depth > lcpPrev)
                cur = cur->parent;
            if(cur->depth == lcpPrev)
                cur = CreateNewLeaf(cur,suffix);
            else{
                int start = SA.order[i-1] + cur->depth;
                int offset = lcpPrev - cur->depth;
                node* mid = BreakEdge(cur,start,offset);
                cur = CreateNewLeaf(mid,suffix);
            }
            if(i < sz-1) lcpPrev = SA.lcp[i];              
        }
    }
    void print(){dfs(root);}
    SuffixTree(){}
};
SuffixTree ST;
int main(){
    string x; cin >> x;
    SA.build(x);
    ST.STfromSA(x);
    ST.print();
    return 0;
}
