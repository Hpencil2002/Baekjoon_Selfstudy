#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<double> vc = vector<double>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    double ans1 = 0.0;
    for (int i = K; i < N - K; i++) {
        ans1 += vc[i];
    }
    ans1 /= (N - K * 2);

    double ans2 = vc[K] * K + vc[N - K - 1] * K;
    for (int i = K; i < N - K; i++) {
        ans2 += vc[i];
    }
    ans2 /= N;

    cout.precision(2);
    cout << fixed;
    cout << ans1 + 1e-13 << "\n" << ans2 + 1e-13;

    return 0;
}