#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> vc = vector<string>(N);
    set<string> st;
    int index = 0;
    for (int i = 0; i < N; i++) {
        cin >> vc[i];

        if (vc[i] == "?") {
            index = i;
        }
        else {
            st.insert(vc[i]);
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;

        if (index > 0) {
            if (str.front() != vc[index - 1].back()) {
                continue;
            }
        }
        if (index + 1 < N) {
            if (str.back() != vc[index + 1].front()) {
                continue;
            }
        }
        if (st.count(str)) {
            continue;
        }

        cout << str;
    }

    return 0;
}