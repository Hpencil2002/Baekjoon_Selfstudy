#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
int ans;

int main() {
    int cnt = 1;

    while (true) {
        cin >> str;
        if (str[0] == '-') {
            return 0;
        }

        ans = 0;
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];

            if (c == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            char c1 = st.top();
            st.pop();
            char c2 = st.top();
            st.pop();

            if (c1 == c2) {
                ans += 1;
            }
            else {
                ans += 2;
            }
        }

        cout << cnt << ". " << ans << "\n";

        cnt += 1;
    }
}