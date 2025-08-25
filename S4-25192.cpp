#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    set<string> st;
    while (N--) {
        string str;
        cin >> str;

        if (str == "ENTER") {
            ans += st.size();
            st.clear();
            continue;
        }

        st.insert(str);
    }
    ans += st.size();

    cout << ans;

    return 0;
}