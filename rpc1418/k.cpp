#include <bits/stdc++.h>
using namespace std;

double dice[6];
double value[6];
int main() {
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		value[i] = i + 1;
	}
	// value[0] * dice[0] = 3.5-value[1]*dice[1]-value[2]*dice[2]-value[3]*dice[3]-value[4]*dice[4]-value[5]*dice[5]
	// pasa a dividir
	double ret = INT_MAX;
	for (int i = 0; i < 6; i++) {
		double ans = 3.5;
		for (int j = 0; j < 6; j++) {
			if (i != j) {
				ans -= (value[j] * dice[j]);
			}
		}
		ans /= dice[i];
		double diff = fabs(value[i] - ans);
		ret = fmin(diff, ret);
	}
	cout.precision(3);
	cout << fixed << ret << "\n";
}
