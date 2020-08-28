#include <bits/stdc++.h>


using namespace std;

class TheSwapsDivTwo {
public:
	int find(vector <int>);
};

int TheSwapsDivTwo::find(vector <int> sequence) {
    set<vector<int> > s;
    for (int i = 0; i < (int)sequence.size(); ++i) {
        for (int j = 0; j < (int)sequence.size(); ++j) {
            if(i == j) continue;
            swap(sequence[i],sequence[j]);
            s.insert(sequence);
            swap(sequence[i],sequence[j]);
        }
    }
	return s.size();
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

