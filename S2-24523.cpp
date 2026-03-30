#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<long long> vc;
stack<int> st;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;

        vc.push_back(a);
    }

    long long cur = vc[N - 1];
    int prev = -1;

    for (int i = N - 1; i >= 0; i--) {
        if (vc[i] == cur) {
            st.push(prev);
        }
        else {
            st.push(i + 2);

            prev = i + 2;
            cur = vc[i];
        }
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}