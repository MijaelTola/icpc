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

using namespace std;

typedef long long ll;
int a,b,n,p;

struct node{
    node* next;
    node* prev;
    string name;
    int phone;
    node(int num, string s){
        name = s;
        phone = num;
        next = prev = NULL;
    }
};

class list{
    node *front;
    node *back;
    public:
        list(){ front = NULL; back = NULL; }
        ~list(){destroylist();}
        void add(int num,string s){
            node *n = new node(num,s);
            if(back == NULL){
                front = n;
                back = n;
            }
            node *temp = front;
            while(temp != NULL){
                if(temp->phone == num){
                    temp->name = s;
                    return;
                }
                temp = temp->next;
            }
            back->next = n;
            n->prev = back;
            back = n;
        }
        string find(int x){
            node *temp = front;
            while(temp != NULL){
                if(temp->phone == x)
                    return temp->name;
                temp = temp->next;
            }
            return "not found";
        }
        void del(int x){
            node *temp = front;
            while(temp != NULL){
                if(temp->phone == x){
                    if(temp->prev != NULL) temp->prev->next = temp->next;
                    else front  = temp->next;
                    if(temp->next != NULL) temp->next->prev = temp->prev;
                    return;
                }
                temp = temp->next;
            }
        }
        void destroylist(){
            node *t = back;
            while(t != NULL){
                node *t2 = t;
                t = t->prev;
                delete t2;
            }
        }

};

list A[100010];
int h(int x){return ((a*x+b)%p)%100010;}

int main(){
    ios::sync_with_stdio(false); cin.tie();
    p = 10000019;
    a = 34;
    b = 2;
    cin >> n;
    while(n--){
        string c,name;int num;
        cin >> c;
        if(c == "add"){
            cin >> num >> name;
            int pos = h(num);
            A[pos].add(num,name);
        }
        if(c == "del"){
            cin >> num;
            int pos = h(num);
            A[pos].del(num);
        }
        if(c == "find"){
            cin >> num;
            int pos = h(num);
            cout << A[pos].find(num) << "\n";
        }
    }
    return 0;
}
