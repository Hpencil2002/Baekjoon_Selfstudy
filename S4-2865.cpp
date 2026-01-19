#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
double ans;
vector<double> vc;

int main() {
    cin >> N >> M >> K;

    vc = vector<double>(N, 0.0);
    for (int i = 0; i < M; i++) {
        int num;
        double ability;

        for (int j = 0; j < N; j++) {
            cin >> num >> ability;
            vc[num - 1] = max(ability, vc[num - 1]);
        }
    }

    sort(vc.begin(), vc.end(), greater<double>());

    for (int i = 0; i < K; i++) {
        ans += vc[i];
    }

    cout << fixed;
    cout.precision(1);
    cout << ans;

    return 0;
}