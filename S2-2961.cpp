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

    int ans = INT32_MAX;
    for (int i = 1; i < (1 << N); i++) {
        int S = 1, B = 0;
        for (int x = 0; x <= N; x++) {
            if (i & (1 << x)) {
                S *= vc[x].first;
                B += vc[x].second;
            }
        }

        ans = min(ans, abs(S - B));
    }

    cout << ans;

    return 0;
}