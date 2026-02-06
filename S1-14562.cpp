#include <iostream>
#include <cmath>
using namespace std;

int S, T;

int solve(int point, int penalty) {
    if (point > T + penalty) {
        return 100;
    }
    else if (point == T + penalty) {
        return 0;
    }

    int a = solve(point * 2, penalty + 3);
    int b = solve(point + 1, penalty);

    return min(a, b) + 1;
}

int main() {
    int C;
    cin >> C;

    while (C--) {
        cin >> S >> T;

        cout << solve(S, 0) << "\n";
    }

    return 0;
}