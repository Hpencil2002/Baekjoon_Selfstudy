#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> vc;

void dfs(vector<char> v, int cur, string str, int conso, int vowel) {
    str.push_back(v[cur]);
    if (v[cur] == 'a' || v[cur] == 'e' || v[cur] == 'i' || v[cur] == 'o' || v[cur] == 'u') {
        vowel += 1;
    }
    else {
        conso += 1;
    }

    if (str.length() == L) {
        if (vowel >= 1 && conso >= 2) {
            cout << str << "\n";
        }

        return;
    }

    for (int i = cur + 1; i < C; i++) {
        dfs(v, i, str, conso, vowel);
    }
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;

        vc.push_back(c);
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i <= C - L; i++) {
        dfs(vc, i, "", 0, 0);
    }

    return 0;
}