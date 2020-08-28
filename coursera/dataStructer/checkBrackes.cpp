#include <iostream>
#include <stack>

using namespace std;
stack<pair<char,int> > s;
bool verify(){
    return s.top().first == '{' or s.top().first == '[' or s.top().first == '(';
}
bool f(char kind){
    while(!s.empty()){
       // cout << s.top() << " "<< kind << endl;
        if(verify()){
            if(s.top().first == kind){
                s.pop();
                return true;
            }
            return false;
        }
        s.pop();
    }
    return false;
}
int main(){
    string x; cin >> x;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == '}') {
            if(!f('{')) return cout << i+1 << endl,0;
            else continue;}
        if(x[i] == ']') {
            if(!f('[')) return cout << i+1 << endl,0;
            else continue;}
        if(x[i] == ')') { 
            if(!f('(')) return cout << i+1 << endl,0;
            else continue;}
        s.push({x[i],i+1});
    }
    while(!s.empty()){
        if(verify()) return cout << s.top().second << endl,0;
        s.pop();
    }
    cout << "Success" << endl;
    return  0;
}
