#include <bits/stdc++.h>

using namespace std;

int sz[110];
char ans[5000][5000];
int main() {

    for (int i = 0; i < 5000; ++i)
        for (int j = 0; j < 5000; ++j)
            ans[i][j] = ' ';
    auto paint = [&] (int pos, char c, int sz, int cur) {
        if(c == '[') {

            int mid = cur / 2;
            int top = mid - sz;
            int bot = mid + sz;

            for (int i = top; i <= bot; ++i)
                ans[i][pos] = '|';

            ans[top][pos] = '+';
            ans[bot][pos] = '+';
            
            ans[top][pos + 1] = '-';
            ans[bot][pos + 1] = '-';

            
        } else {
            int mid = cur / 2;
            int top = mid - sz;
            int bot = mid + sz;

            for (int i = top; i <= bot; ++i)
                ans[i][pos] = '|';

            ans[top][pos] = '+';
            ans[bot][pos] = '+';
            
            ans[top][pos - 1] = '-';
            ans[bot][pos - 1] = '-';
        }
    };
    

   
    int n;
    string s;
    cin >> n >> s;

    auto ver = [&] (int k) {
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if(c == '[') {
                if(st.empty()) {
                    st.push(k);
                } else {
                    st.push(st.top() - 1);
                }
                sz[i] = st.top();
            } else {
                sz[i] = st.top();
                st.pop();
            }
            if(!st.empty() and st.top() == 0) return 0;
        }
        return 1;
    };

    int id = -1;
    for (int i = 1; i < (int)s.size(); ++i) {
        if(ver(i)) {
            id = i;
            break;
        }
    }
    
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if(i == 0) {
            paint(p, s[i], sz[i], (2 * id - 1) + 2);
            p++;
        } else {
            if(s[i] != s[i - 1] and s[i] == ']' and s[i - 1] == '[') p += 3;
            paint(p, s[i], sz[i], (2 * id - 1) + 2);
            p++;
        }
    }

    for (int i = 0; i < (2 * id - 1) + 2; ++i) {
        for (int j = 0; j < p; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }


    return 0;
}

