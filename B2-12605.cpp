#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt = 1;
    cin.ignore();
    while (N--) {
        string str;
        getline(cin, str);

        stack<string> st;
        string tmp = "";
        string ans = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                st.push(tmp);
                st.push(" ");
                tmp.clear();
            }
            else {
                tmp += str[i];
            }
        }

        st.push(tmp);

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        cout << "Case #" << cnt << ": " << ans << "\n";
        cnt += 1;
    }

    return 0;
}