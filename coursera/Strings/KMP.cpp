#include <iostream>

using namespace std;

int b[1900010];
void kmp(string &T, string &P){
	string S = P + '$' + T;
	int cur = 0;
	for (int i = 1; i < (int)S.size(); ++i){
		while(cur > 0 and S[i] != S[cur]) cur = b[cur-1];
		if(S[i] == S[cur])  cur++;
		else cur = 0;
		b[i] = cur;
	}
	for (int i = P.size()+1; i < (int)S.size(); ++i)
		if(b[i] == (int)P.size()) 
			cout << i-2*P.size() << " ";
}
int main(){
	string text,pattern;
	cin >> text >> pattern;
	kmp(text, pattern);
}
