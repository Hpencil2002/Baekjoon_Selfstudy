#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return (a.first * a.second) > (b.first * b.second);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int J, N;
        cin >> J >> N;

        vector<pair<int, int>> vc = vector<pair<int, int>>(N);
        for (int i = 0; i < N; i++) {
            cin >> vc[i].first >> vc[i].second;
        }

        sort(vc.begin(), vc.end(), comp);

        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += 1;
            J -= vc[i].first * vc[i].second;

            if (J <= 0) {
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}