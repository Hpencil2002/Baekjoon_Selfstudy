#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int N, cnt = 0;
    string input;
    cin >> N;

    for (int i = 0; i < N; i++) {
        stack<char> st;

        cin >> input;
        for (int j = 0; j < input.length(); j++) {
            if (st.empty()) {
                st.push(input[j]);
            }
            else {
                if (st.top() == input[j]) {
                    st.pop();
                }
                else {
                    st.push(input[j]);
                }
            }
        }

        if (st.empty()) {
            cnt += 1;
        }
    }

    cout << cnt << "\n";

    return 0;
}