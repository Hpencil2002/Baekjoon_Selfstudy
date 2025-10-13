#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string S;
    cin >> S;

    stack<char> st;
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            st.push(S[i]);
        }
        else {
            if (!st.empty()) {
                st.pop();
            }
            else {
                ans += 1;
            }
        }
    }

    while (!st.empty()) {
        ans += 1;
        st.pop();
    }

    cout << ans;

    return 0;
}