#include <iostream>
#include <vector>
using namespace std;

int A, B;

pair<int, int> solve(int a, int b) {
    if (a == 0) {
        return { -1, 0 };
    }
    if (b == 0) {
        return { 0, -1 };
    }

    if (a > b) {
        pair<int, int> p = solve(a % b, b);
        return { p.first + a / b, p.second };
    }
    else {
        pair<int, int> p = solve(a, b % a);
        return { p.first, p.second + b / a };
    }
}

int main() {
    cin >> A >> B;
    pair<int, int> p = solve(A, B);

    cout << p.first << ' ' << p.second;

    return 0;
}