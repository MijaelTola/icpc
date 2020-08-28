#include <iostream>
using namespace std;
int main(){
	int i;
	string s1, s2, aux1, aux2;
	cin>>s1>>s2;
	if(s1==s2){
		cout<<"yes";
	}
	else{
		if(s1.length()<8)
			cout<<"no";
		else{
			
			if(s2.size()+1 == s1.size() || s2.size()-1 == s1.size() || s2.size() == s1.size()){
				for(i=0; i<s1.size() && i<s2.size() ;i++){
					if(!(s1[i]==s2[i])){
						aux1.push_back(s1[i]);
						aux2.push_back(s2[i]);
					}
				}
				aux1+=s1.substr(i, s1.size());
				aux2+=s2.substr(i, s2.size());
				s1.clear(); s2.clear();
				for(int i= min(aux1.size(), aux2.size()); i>=0; i--){
					if(!(aux1[i]==aux2[i])){
						s1.push_back(aux1[i]);
						s2.push_back(aux2[i]);
					}
				}
				
				cout<<s1<<endl;
				cout<<s2<<endl;
				if(max(s1.size(), s2.size())==1)
					cout<<"yes";
				else
					cout<<"no";
				
			}
			else
				cout<<"no";
		}
	}
return 0;
}
