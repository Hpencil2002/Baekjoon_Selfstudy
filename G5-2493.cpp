#include <iostream>
#include <stack>
using namespace std;

int N;
stack<pair<int, int>> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int height;
        cin >> height;

        while (!st.empty()) {
            if (height < st.top().second) {
                cout << st.top().first << ' ';

                break;
            }

            st.pop();
        }

        if (st.empty()) {
            cout << 0 << ' ';
        }

        st.push({ i + 1, height });
    }

    return 0;
}