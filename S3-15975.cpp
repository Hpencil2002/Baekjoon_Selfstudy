#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N;
    cin >> N;

    vector<vector<long long>> vc = vector<vector<long long>>(N, vector<long long>());
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;

        y -= 1;
        vc[y].push_back(x);
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        sort(vc[i].begin(), vc[i].end());

        if (vc[i].size() <= 1) {
            continue;
        }

        for (int j = 0; j < vc[i].size(); j++) {
            long long cur = vc[i][j];

            long long left = j - 1 >= 0 ? vc[i][j - 1] : -10000000001;
            long long right = j + 1 < vc[i].size() ? vc[i][j + 1] : 10000000001;

            ans += min(cur - left, right - cur);
        }
    }

    cout << ans;

    return 0;
}