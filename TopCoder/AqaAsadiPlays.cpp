#include <bits/stdc++.h>

using namespace std;

class AqaAsadiPlays {
public:
	int getMin(vector <int>);
};

map<int, vector<int> > mp;
void factors(int n) {
    
    vector<pair<int,int> > v;
    for (int i = 2; i * i <= n; ++i) {
        int cnt = 0;
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        if(cnt) v.emplace_back(i, cnt);
    }
    
    if(n > 1) v.emplace_back(n, 1);
    for (auto p: v) {
        mp[p.first].push_back(p.second);
    }
}

int AqaAsadiPlays::getMin(vector <int> A) {
    sort(A.begin(), A.end());

    for (auto x: A) 
        factors(x);

    int ans = -1;
    mp[1].push_back(1);
    for (auto p: mp) {
        vector<int> &v = p.second;
        sort(v.begin(), v.end());
        int cur = 0;
        int pw = 1;
        
        for (int i = 0; i < (int)v.size(); ++i) {
            while(cur < v[i]) {
                cur++;
                pw *= p.first;
            }
            int cnt = 0;
            bool flag = 1;
            for (auto x: A) {
                if(x % pw != 0) {
                    cnt++;
                    flag &= x < pw;
                }
            }
            int sz = A.size() - cnt;
            //cout << pw << " " << cnt << ": " << sz << "\n";
            flag &= sz < (int)A.size();
            if(flag) ans = max(ans, sz);
        }

        //exit(0);
    }
    return ans;
}


double test0() {
	int t0[] = {1000000000, 1000000000, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AqaAsadiPlays * obj = new AqaAsadiPlays();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {4, 4, 1, 3, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AqaAsadiPlays * obj = new AqaAsadiPlays();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {2, 8, 3, 12, 16};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AqaAsadiPlays * obj = new AqaAsadiPlays();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {47, 47};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AqaAsadiPlays * obj = new AqaAsadiPlays();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	test0();
	
    test1();
	
	test2();
	
	test3();
	
}

//Powered by [KawigiEdit] 2.0!
