#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<int> st;
    for (int i = 0; i < N; i++) {
        int order;
        cin >> order;

        switch (order) {
            case 1:
                int x;
                cin >> x;
                st.push(x);
                break;
            case 2:
                if (!st.empty()) {
                    cout << st.top() << "\n";
                    st.pop();
                }
                else {
                    cout << "-1\n";
                }
                break;
            case 3:
                cout << st.size() << "\n";
                break;
            case 4:
                cout << (st.empty() ? 1 : 0) << "\n";
                break;
            case 5:
                cout << (st.empty() ? -1 : st.top()) << "\n";
                break;
        }
    }

    return 0;
}