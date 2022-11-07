#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<char> st;
    string input;
    int ans = 0, tmp = 1;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            tmp *= 2;
            st.push(input[i]);
        }
        else if (input[i] == '[') {
            tmp *= 3;
            st.push(input[i]);
        }
        else if (input[i] == ')') {
            if (st.empty() || st.top() != '(') {
                ans = 0;
                break;
            }

            if (input[i-1] == '(') {
                ans += tmp;
                tmp /= 2;
                st.pop();
            }
            else {
                tmp /= 2;
                st.pop();
            }
        }
        else if (input[i] == ']') {
            if (st.empty() || st.top() != '[') {
                ans = 0;
                break;
            }

            if (input[i-1] == '[') {
                ans += tmp;
                tmp /= 3;
                st.pop();
            }
            else {
                tmp /= 3;
                st.pop();
            }
        }
    }

    if (!st.empty()) {
        ans = 0;
    }

    cout << ans << "\n";

    return 0;
}