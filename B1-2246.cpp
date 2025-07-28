#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main() {
    int N, D, C;
    vector<pair<int, int>> vc;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> D >> C;
        vc.push_back({D, C});
    }

    sort(vc.begin(), vc.end(), comp);

    int ans = 1;
    int nowD = vc[0].first, nowC = vc[0].second;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (vc[j].first > nowD && vc[j].second < nowC) {
                ans += 1;
                nowD = vc[j].first;
                nowC = vc[j].second;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}