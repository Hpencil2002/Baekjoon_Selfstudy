#include <iostream>
#include <stack>
using namespace std;

int N, height;
stack<int> st;
long long ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> height;

        if (st.empty()) {
            st.push(height);

            continue;
        }

        while (!st.empty() && st.top() <= height) {
            st.pop();
        }
        ans += st.size();

        st.push(height);
    }

    cout << ans;

    return 0;
}