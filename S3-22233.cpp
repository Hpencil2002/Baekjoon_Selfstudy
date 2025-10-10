#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    set<string> st;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        st.insert(str);
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;

        stringstream ss(str);
        while (getline(ss, str, ',')) {
            if (st.find(str) == st.end()) {
                continue;
            }

            st.erase(str);
        }

        cout << st.size() << "\n";
    }

    return 0;
}