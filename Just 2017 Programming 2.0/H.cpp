#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int inf = 1 << 30;

int a[N], b[N];


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		a[n] = inf;
		stack <int> s;
		s.push(n);
		for (int i = n - 1; i >= 0; i--) {
			while (a[s.top()] <= a[i]) s.pop();
			b[i] = a[s.top()];
			s.push(i);
		}
		for (int i = 0; i < n; i++) {
			if (b[i] == inf) b[i] = -1;
			printf("%d ", b[i]);
		}
		puts("");
	}
	return 0;
}