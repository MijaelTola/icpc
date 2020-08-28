#include <iostream>
#include <queue>
using namespace std;
int main(){
	int i;
	string s1, s2;
	deque<char> DQ1;
	deque<char> DQ2;
	cin>>s1;
	cin>>s2;
	if(s1==s2){
		cout<<"yes";
	}
	else{
		if(s1.size() < 8)
			cout<<"no";
		else{
			
			if(s2.size()+1 == s1.size() || s2.size()==s1.size()){
				
			
			for(int i=0; i<s1.size(); i++)
				DQ1.push_back(s1[i]);
			for(int i=0; i<s2.size(); i++)
				DQ2.push_back(s2[i]);
			
			//if((DQ2.size()+1) == DQ1.size() || (DQ2.size()-1) == DQ1.size() || DQ2.size() == DQ1.size()){
			
			while(!DQ1.empty() && !DQ2.empty()){
				if(DQ1.front()==DQ2.front()){
					DQ1.pop_front();
					DQ2.pop_front();
				}
				else{
					if((!DQ1.empty() && !DQ2.empty()) && DQ1.back() == DQ2.back()){
						DQ1.pop_back();
						DQ2.pop_back();
					}
					else
						break;
				}
				//if(DQ1.size()==1 && DQ2.size()==1 && DQ1.front()!=DQ2.front())
				//	break;
				
			}
			//cout<<DQ1.size()<<"-"<<DQ2.size()<<endl;
			if(max(DQ1.size(), DQ2.size()) == 1)
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
