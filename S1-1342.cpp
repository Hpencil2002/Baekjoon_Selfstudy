#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string S;
int len, ans;
int alp[26];
char arr[10];
bool Select[10];
vector<char> vc;

bool check() {
    for (int i = 0; i < vc.size() - 1; i++) {
        if (vc[i] == vc[i + 1]) {
            return false;
        }
    }

    return true;
}

void dfs(int cnt) {
    if (cnt == len) {
        if (check()) {
            ans += 1;
        }

        return;
    }

    for (int i = 0; i < len; i++) {
        if (Select[i] == true) {
            continue;
        }

        Select[i] = true;
        vc.push_back(arr[i]);
        dfs(cnt + 1);
        Select[i] = false;
        vc.pop_back();
    }
}

int fac(int n) {
    int res = 1;

    for (int i = n; i >= 1; i--) {
        res *= i;
    }

    return res;
}

int main() {
    cin >> S;
    len = S.length();

    for (int i = 0; i < len; i++) {
        alp[S[i] - 'a'] += 1;
        arr[i] = S[i];
    }

    dfs(0);

    for (int i = 0; i < 26; i++) {
        if (alp[i] > 1) {
            ans /= fac(alp[i]);
        }
    }

    cout << ans;

    return 0;
}