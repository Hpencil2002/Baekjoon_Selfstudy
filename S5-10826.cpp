#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string fib[10001];

string fibb(string a, string b) {
    string res = "";
    int carry = 0;

    while (a.size() || b.size()) {
        int num1 = 0, num2 = 0;

        if (a.size()) {
            num1 = a.back() - '0';
            a.pop_back();
        }
        if (b.size()) {
            num2 = b.back() - '0';
            b.pop_back();
        }

        int sum = num1 + num2 + carry;
        res += to_string(sum % 10);
        carry = sum / 10;
    }

    if (carry) {
        res += "1";
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    int n;
    cin >> n;

    fib[0] = "0";
    fib[1] = "1";
    for (int i = 2; i <= n; i++) {
        fib[i] = fibb(fib[i - 1], fib[i - 2]);
    }

    cout << fib[n];

    return 0;
}