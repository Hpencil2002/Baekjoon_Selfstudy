#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> vc;
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        if (A < N) {
            vc.push_back({A, B});
        }
        else {
            cnt += 1;
        }
    }

    sort(vc.begin(), vc.end(), comp);

    int ans = 0;
    if (M - 1 == cnt) {
        cout << 0;
    }
    else {
        for (int i = 0; i < M - 1 - cnt; i++) {
            ans += N - vc[i].first;
        }

        cout << ans;
    }

    return 0;
}