#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<pair<int, int>> vc;
long double ans;

long double solve(int i, int j) {
    long double a = vc[0].first;
    long double b = vc[0].second;
    long double c = vc[i].first;
    long double d = vc[i].second;
    long double e = vc[j].first;
    long double f = vc[j].second;

    return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        vc.push_back({ a, b });
    }

    for (int i = 1; i < N - 1; i++) {
        ans += solve(i, i + 1);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(ans);

    return 0;
}