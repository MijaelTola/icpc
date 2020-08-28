#include <bits/stdc++.h> 
using namespace std;

struct BinaryCode {

    vector<string> decode(string message) {
        string ans1 = "";
        string ans2 = "";
        vector<int> x;
        x.push_back(0);

        for (int i = 1; i < (int)message.size(); ++i) {
            if(i == 1) x.push_back((int)(message[i - 1] - '0') - x.back());
            else x.push_back((int)(message[i - 1] - '0') - x[i - 1] - x[i - 2]);
        }

        for (int p: x) {
            if(p != 0 and p != 1) {
                ans1 = "NONE";
                break;
            }
            ans1 += (char)(p + '0');
        }

        for (int i = 0; i < (int)message.size(); ++i) {
            int l = 0, r = 0;
            if(i)  l = x[i - 1];
            if(i + 1 < (int)message.size())r = x[i + 1];
            if(message[i] - '0' != l + r + x[i]) {
                ans1 = "NONE";
                break;
            }
        }

        x.clear();
        x.push_back(1);

        for (int i = 1; i < (int)message.size(); ++i) {
            if(i == 1) x.push_back((int)(message[i - 1] - '0') - x.back());
            else x.push_back((int)(message[i - 1] - '0') - x[i - 1] - x[i - 2]);
        }

        for (int p: x) {
            if(p != 0 and p != 1) {
                ans2 = "NONE";
                break;
            }
            ans2 += (char)(p + '0');
        }

        for (int i = 0; i < (int)message.size(); ++i) {
            int l = 0, r = 0;
            if(i)  l = x[i - 1];
            if(i + 1 < (int)message.size())r = x[i + 1];
            if(message[i] - '0' != l + r + x[i]) {
                ans2 = "NONE";
                break;
            }
        }

        return {ans1, ans2};
    }
};
int main() {
    BinaryCode b;
    auto v = b.decode("12221112222221112221111111112221111");
    cout << v[0] << " " << v[1]<< "\n";
    return 0;
}

