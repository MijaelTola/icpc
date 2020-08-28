#include <bits/stdc++.h>

using namespace std;

class EasyPartition {
public:
	string getPartition(int);
};

int n;
int dp[400][800][110];

int f(int pos, int sum, int cnt) {
    if(pos == 8 * n + 1) {
        return sum == 4 * n * n and cnt == 2 * n;
    }
    int &ans = dp[pos][sum][cnt];
    if(ans != -1) return ans;
    ans = 0;
    ans |= f(pos + 1, sum + pos, cnt + 1);
    ans |= f(pos + 1, sum, cnt);
    return ans;
}
string ans;

void r(int pos, int sum, int cnt) {
    if(pos == 8 * n + 1) return;
    if(f(pos + 1, sum + pos, cnt + 1)) {
        ans += "1";
        r(pos + 1, sum + pos, cnt + 1);
    } else {
        ans += "0";
        r(pos + 1, sum, cnt);
    }
}

string EasyPartition::getPartition(int N) {
	n = N;
    memset(dp, -1, sizeof dp);
    if(!f(1, 0, 0)) return "";
    ans = "";
    r(1, 0, 0);
    return ans;
}


double test0() {
	int p0 = 1;
	EasyPartition * obj = new EasyPartition();
	clock_t start = clock();
	string my_answer = obj->getPartition(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "10100000";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	EasyPartition * obj = new EasyPartition();
	clock_t start = clock();
	string my_answer = obj->getPartition(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "0110110000000000";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	EasyPartition * obj = new EasyPartition();
	clock_t start = clock();
	string my_answer = obj->getPartition(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "010110110100000000000000";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 4;
	EasyPartition * obj = new EasyPartition();
	clock_t start = clock();
	string my_answer = obj->getPartition(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "01010110110101000000000000000000";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
    test3();
    return 0;
}


//Powered by [KawigiEdit] 2.0!
