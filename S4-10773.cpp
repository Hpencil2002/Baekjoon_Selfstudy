#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k, num, cnt;
    int hap = 0;
    stack<int> st;

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> num;

        if (num != 0) {
            st.push(num);
        }
        else {
            st.pop();
        }
    }

    cnt = st.size();
    for (int i = 0; i < cnt; i++) {
        hap += st.top();
        st.pop();
    }
    cout << hap;

    return 0;
}