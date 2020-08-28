#include <bits/stdc++.h>

using namespace std;

bool OK(int a, int b, int c) {
	return a >= 4 && b >= 4 && c >= 2;
}

int main() {
	int n;
	//scanf("%d", &n);
	cin >> n;
	while (n-- > 0) {
		string str;
		cin >> str;
		int cntL = 0, cntD = 0, cntS = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] <= 'z' && str[i] >= 'a' ) cntL++;
			if (str[i] <= 'Z' && str[i] >= 'A' ) cntL++;
			if (str[i] <= '9' && str[i] >= '0') cntD++;
			if (str[i] == '@' || str[i] == '?' || str[i] == '!') cntS++;
		}
		bool z = OK(cntL, cntD, cntS);
		bool ok1 = OK(cntL + 1, cntD, cntS), ok2 = OK(cntL, cntD + 1, cntS), ok3 = OK(cntL, cntD, cntS + 1);
		if (ok1 && ok2 && ok3) {
			cout << "The last character can be any type.\n";
		}
		else {
			if (ok1 && !z) {
				cout << "The last character must be a letter.\n";
			}
			if (ok2 && !z) {
				cout << "The last character must be a digit.\n";
			}
			if (ok3 && !z) {
				cout << "The last character must be a symbol.\n";
			}
		}
	}
	return 0;
}