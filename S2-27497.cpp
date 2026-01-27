#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int N;
deque<char> dq;
stack<int> st;

int main() {
    cin >> N;

    while (N--) {
        int x;
        cin >> x;

        if (x == 1) {
            st.push(1);

            char c;
            cin >> c;

            dq.push_back(c);
        }
        else if (x == 2) {
            st.push(2);

            char c;
            cin >> c;

            dq.push_front(c);
        }
        else if (x == 3) {
            if (dq.empty()) {
                continue;
            }

            if (st.top() == 1) {
                dq.pop_back();
                st.pop();
            }
            else if (st.top() == 2) {
                dq.pop_front();
                st.pop();
            }
        }
    }

    if (dq.empty()) {
        cout << 0;
    }
    else {
        while (!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
    }

    return 0;
}