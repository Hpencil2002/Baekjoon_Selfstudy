#include <iostream>
#include <string>
using namespace std;

string S;
bool ans = true;

void solve(string& str, int start, int end, int recurSize) {
    if (recurSize == 1) {
        return;
    }

    for (int i = start, j = end - 1; i < recurSize / 2; i++, j--) {
        if (str[i] != str[j]) {
            ans = false;

            return;
        }
    }

    if (int(str.length()) % 2 == 0) {
        solve(str, start, end / 2, recurSize / 2);
        solve(str, end / 2, end, recurSize / 2);
    }
    else {
        solve(str, start, end / 2, recurSize / 2);
        solve(str, end / 2 + 1, end, recurSize / 2);
    }
}

int main() {
    cin >> S;

    solve(S, 0, S.length(), S.length());

    if (ans) {
        cout << "AKARAKA";
    }
    else {
        cout << "IPSELENTI";
    }

    return 0;
}