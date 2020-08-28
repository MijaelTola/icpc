#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

vector<int> p;
bool prime[1000100];
int ans6[1000100];
int ans5[100010];
int ans4[10001];
int ans3[1000];
int ans2[100];
int ans1[10];
void criba(){
	memset(prime,false,sizeof prime);
	for (int i = 2; i*i < 1000000; ++i){
		int c = i+i;
		while(c < 1000000){
			prime[c] = true;
			c += i;
		}
	}
	prime[0] = prime[1] = true;
    for (int i = 2; i < 1000000; ++i)
        if(!prime[i]) p.push_back(i);
 }
int n;
int digit[7];

//optimiza
int convert(string x){
	int ans = 0;
	for (int i = 0; i < (int)x.size(); ++i){
		ans += (x[i]-'0');
		if(i+1 < (int)x.size()) ans *= 10;
	}
	return ans;
}

//optimize
int convert(){
	return (digit[5]*100000+digit[4]*10000+digit[3]*1000+digit[2]*100+digit[1]*10+digit[0]);
}
void clean(){
	 digit[0] = digit[1] = digit[2] = digit[3] = digit[4] = digit[5] = digit[6] = 0; 
}
//optimize
void convert(int x){
	digit[0] = x%10;x/=10;
	digit[1] = x%10;x/=10;
	digit[2] = x%10;x/=10;
	digit[3] = x%10;x/=10;
	digit[4] = x%10;x/=10;
	digit[5] = x%10;x/=10;
}

queue<pair<int,int> > q6;
queue<pair<int,int> > q5;
queue<pair<int,int> > q4;
queue<pair<int,int> > q3;
queue<pair<int,int> > q2;
queue<pair<int,int> > q1;

void bfs(){
		
    memset(ans6,-1,sizeof ans6);
    memset(ans5,-1,sizeof ans5);
    memset(ans4,-1,sizeof ans4);
    memset(ans3,-1,sizeof ans3);
    memset(ans2,-1,sizeof ans2);
    memset(ans1,-1,sizeof ans1);
        while(!q6.empty()){
			int u = q6.front().first;
			int c = q6.front().second;
			q6.pop();
			if(ans6[u] != -1) continue;
			ans6[u] = c;
			clean();
			convert(u);
			for (int i = 0; i < 6; ++i){
				digit[i] = (digit[i]+1)%10;
				int b = convert();
				q6.push({b,c+1});
				
				digit[i] = (digit[i]-1+10)%10;
				digit[i] = (digit[i]-1+10)%10;
				
				b = convert();
				
				q6.push({b,c+1});
				digit[i] = (digit[i]+1)%10;
			}
		}

		while(!q5.empty()){
			int u = q5.front().first;
			int c = q5.front().second;
			q5.pop();
			if(ans5[u] != -1) continue;
			ans5[u] = c;
			clean();
			convert(u);
			for (int i = 0; i < 5; ++i){
				digit[i] = (digit[i]+1)%10;
				int b = convert();
				q5.push({b,c+1});
				
				digit[i] = (digit[i]-1+10)%10;
				digit[i] = (digit[i]-1+10)%10;
				
				b = convert();
				
				q5.push({b,c+1});
				digit[i] = (digit[i]+1)%10;
			}
		}
		while(!q4.empty()){
			int u = q4.front().first;
			int c = q4.front().second;
			q4.pop();
			if(ans4[u] != -1) continue;
			ans4[u] = c;
			clean();
			convert(u);
			for (int i = 0; i < 4; ++i){
				digit[i] = (digit[i]+1)%10;
				int b = convert();
				q4.push({b,c+1});
				
				digit[i] = (digit[i]-1+10)%10;
				digit[i] = (digit[i]-1+10)%10;
				
				b = convert();
				
				q4.push({b,c+1});
				digit[i] = (digit[i]+1)%10;
			}
		}
		while(!q3.empty()){
			int u = q3.front().first;
			int c = q3.front().second;
			q3.pop();
			if(ans3[u] != -1) continue;
			ans3[u] = c;
			clean();
			convert(u);
			for (int i = 0; i < 3; ++i){
				digit[i] = (digit[i]+1)%10;
				int b = convert();
				q3.push({b,c+1});
				
				digit[i] = (digit[i]-1+10)%10;
				digit[i] = (digit[i]-1+10)%10;
				
				b = convert();
				
				q3.push({b,c+1});
				digit[i] = (digit[i]+1)%10;
			}
		}

		while(!q2.empty()){
			int u = q2.front().first;
			int c = q2.front().second;
			q2.pop();
			if(ans2[u] != -1) continue;
			ans2[u] = c;
			clean();
			convert(u);
			for (int i = 0; i < 2; ++i){
				digit[i] = (digit[i]+1)%10;
				int b = convert();
				q2.push({b,c+1});
				
				digit[i] = (digit[i]-1+10)%10;
				digit[i] = (digit[i]-1+10)%10;
				
				b = convert();
				
				q2.push({b,c+1});
				digit[i] = (digit[i]+1)%10;
			}
		}
		while(!q1.empty()){
			int u = q1.front().first;
			int c = q1.front().second;
			q1.pop();
			if(ans1[u] != -1) continue;
			ans1[u] = c;
			clean();
			convert(u);
			for (int i = 0; i < 1; ++i){
				digit[i] = (digit[i]+1)%10;
				int b = convert();
				q1.push({b,c+1});
				
				digit[i] = (digit[i]-1+10)%10;
				digit[i] = (digit[i]-1+10)%10;
				
				b = convert();
				
				q1.push({b,c+1});
				digit[i] = (digit[i]+1)%10;
			}
		}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	criba();
	
  
    for (int i = 0; i < (int)p.size(); ++i){
           q6.push({p[i],0});
           if(log10(p[i]) <= 5)q5.push({p[i],0});
           if(log10(p[i]) <= 4)q4.push({p[i],0});
           if(log10(p[i]) <= 3)q3.push({p[i],0});
           if(log10(p[i]) <= 2)q2.push({p[i],0});
           if(log10(p[i]) <= 1)q1.push({p[i],0});
    }
    bfs();
    int t;
	cin >> t;
	while(t--){
		cin >> n;
	//	n = 6;
        string x; cin >> x;
		int a = convert(x);	
        switch (n){
            case 1:
                cout << ans1[a];
                break;
            
            case 2:
                cout << ans2[a];
                break;
            case 3:
                cout << ans3[a];
                break;
            case 4:
                cout << ans4[a];
                break;
            case 5:
                cout <<ans5[a];
                break;
            case 6:
                cout << ans6[a];
        }
        cout <<"\n";
    }
	return 0;
}

