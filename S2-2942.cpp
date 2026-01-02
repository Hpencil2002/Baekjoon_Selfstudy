#include <iostream>
#include <vector>
using namespace std;

int R, G;
vector<int> vc;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        if (a > b) {
            return gcd(b, a % b);
        }
        else {
            return gcd(a, b % a);
        }
    }
}

int solve(int N) {
    vc.clear();

    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            vc.push_back(i);
        }
    }

    return vc.back();
}

int main() {
    cin >> R >> G;

    solve(gcd(R, G));

    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i] << ' ' << R / vc[i] << ' ' << G / vc[i] << "\n";
    }

    return 0;
}