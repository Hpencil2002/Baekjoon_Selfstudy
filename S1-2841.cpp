#include <iostream>
#include <stack>
using namespace std;

int N, P;
int ans;
stack<int> st[8];

int main() {
    cin >> N >> P;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if (st[a].empty()) {
            st[a].push(b);
            ans += 1;
        }
        else if (st[a].top() < b) {
            st[a].push(b);
            ans += 1;
        }
        else if (st[a].top() > b) {
            while (st[a].top() > b) {
                st[a].pop();
                ans += 1;

                if (st[a].empty()) {
                    st[a].push(b);
                    ans += 1;
                }
            }

            if (st[a].top() < b) {
                st[a].push(b);
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}