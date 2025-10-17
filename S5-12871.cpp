#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    string s, t;
    cin >> s >> t;

    int tmp = lcm(s.size(), t.size());

    string fs = "", ft = "";
    for (int i = 0; i < tmp / s.size(); i++) {
        fs += s;
    }
    for (int i = 0; i < tmp / t.size(); i++) {
        ft += t;
    }

    if (fs == ft) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}