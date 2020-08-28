#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    string x;
 
    cin >> x;
    string profix = "";
    stack<char> help;
    // infix to postfix
    for (int i = 0; i < x.size(); ++i)
    {
        if(isdigit(x[i])) profix += x[i];
        else{
            if(x[i] == '+' or x[i] == '-'){
                if(!help.empty()){
                    while(help.top() == '*' or help.top() == '/'){
                        profix += help.top();
                        help.pop();
                    }
                }
         	       
            }
			help.push(x[i]);       
		}
    }
    while(!help.empty()){
        profix += help.top(); help.pop();
    }
    //postfix calculator
   stack<double> d;
    int pos = 0;
    while(pos < profix.size()){
        if(isdigit(profix[pos])) d.push(profix[pos]-'0');
        else{
            double a = d.top(); d.pop();
            double b = d.top(); d.pop();
            if(profix[pos] == '-') d.push(a-b); 
            if(profix[pos] == '+') d.push(a+b);
            if(profix[pos] == '*') d.push(a*b);
            if(profix[pos] == '/'){
            	if(a == 0) return cout << "division entre cero",0;
            	d.push(b/a);
            }
        }
        pos++;
    }
    cout.precision(2);
    cout << fixed <<d.top();
    return 0;
}
