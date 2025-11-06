#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> vc = vector<pair<int, int>>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i].first >> vc[i].second;
    }

    long long totalDist = 0;
    vector<long long> dists = vector<long long>(N);
    for (int i = 1; i < N; i++) {
        long long dist = abs(vc[i - 1].first - vc[i].first) + abs(vc[i - 1].second - vc[i].second);
        dists[i] = dist;
        totalDist += dist;
    }

    long long ans = totalDist;
    for (int i = 1; i < N - 1; i++) {
        long long dist1 = dists[i] + dists[i + 1];
        long long dist2 = abs(vc[i - 1].first - vc[i + 1].first) + abs(vc[i - 1].second - vc[i + 1].second);

        int sub = dist1 - dist2;
        ans = min(ans, totalDist - sub);
    }

    cout << ans;

    return 0;
}