#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
long long ans;
vector<long long> vc;
vector<long long> cost;

int main() {
    cin >> N >> K;

    vc = vector<long long>(N);
    cost = vector<long long>(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    for (int i = 1; i < N; i++) {
        cost[i - 1] = vc[i] - vc[i - 1];
    }

    sort(cost.begin(), cost.end());

    for (int i = 0; i < N - K; i++) {
        ans += cost[i];
    }

    cout << ans;

    return 0;
}