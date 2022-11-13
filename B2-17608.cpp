#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    int h;
    int count = 0, tmp = 0;
    stack<int> st;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h;
        st.push(h);
    }

    while(!st.empty()) {
        if (st.top() > tmp) {
            count += 1;
            tmp = st.top();
        }
        st.pop();
    }

    cout << count << "\n";
    return 0;
}