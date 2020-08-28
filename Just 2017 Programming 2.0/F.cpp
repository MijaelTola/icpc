	#include <bits/stdc++.h>

	using namespace std;

	int main() {
		int n;
		while (scanf("%d", &n) != EOF) {
			set <int> S;
			for (int i = 0; i < n; i++) {
				int x;
				scanf("%d", &x);
				S.insert(x);
			}
			int m;
			scanf("%d", &m);
			for (int i = 0; i < m; i++) {
				int x;
				scanf("%d", &x);
				auto it = S.lower_bound(x);
				if (it == S.end()) {
					puts("Dr. Samer cannot take any offer :(.");
				}
				else {
					printf("%d\n", *it);
				}
			}	
		}
		return 0;
	}