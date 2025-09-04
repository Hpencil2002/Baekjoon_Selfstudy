#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string S;
    cin >> S;

    set<string> st;
    for (int i = 0; i < S.size(); i++) {
        for (int j = i; j < S.size(); j++) {
            st.insert(S.substr(i, j - i + 1));
        }
    }

    cout << st.size();

    return 0;
}