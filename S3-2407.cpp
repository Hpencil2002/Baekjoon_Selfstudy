#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string fac[101][101];

string bigNum(string str1, string str2) {
    int sum = 0;
    string res;

    while (!str1.empty() || !str2.empty() || sum) {
        if (!str1.empty()) {
            sum += str1.back() - '0';
            str1.pop_back();
        }
        if (!str2.empty()) {
            sum += str2.back() - '0';
            str2.pop_back();
        }

        res.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}

string comb(int n, int r) {
    if (n == r || r == 0) {
        return "1";
    }

    string &res = fac[n][r];
    if (res != "") {
        return res;
    }

    res = bigNum(comb(n - 1, r - 1), comb(n - 1, r));

    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << comb(n, m);

    return 0;
}