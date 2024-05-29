#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> st;
    string input;
    int total = 0;

    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            st.push(input[i]);
        }
        else if (input[i] == ')' && input[i - 1] == '(') {
            st.pop();
            total += st.size();
        }
        else {
            total += 1;
            st.pop();
        }
    }

    cout << total << "\n";

    return 0;
}