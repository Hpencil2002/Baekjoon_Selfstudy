#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc[5001];
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        vc[y].push_back(x);
    }

    long long ans = 0;
    for (int i = 1; i < 5001; i++) {
        if (vc[i].empty()) {
            continue;
        }

        sort(vc[i].begin(), vc[i].end());

        ans += vc[i][1] - vc[i][0];

        for (int j = 1; j < vc[i].size() - 1; j++) {
            int x = vc[i][j];

            ans += min(x - vc[i][j - 1], vc[i][j + 1] - x);
        }

        int index = vc[i].size() - 1;

        ans += vc[i][index] - vc[i][index - 1];
    }

    cout << ans;

    return 0;
}