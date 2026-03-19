#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<pair<int, int>> vc;
int ans;

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;

        vc.push_back({ s, e });
    }

    sort(vc.begin(), vc.end());

    int s = vc[0].first;
    int e = vc[0].first + L;
    for (int i = 0; i < vc.size(); i++) {
        if (s < vc[i].first) {
            s = vc[i].first;
            e = vc[i].first + L;
        }

        while (s < vc[i].second) {
            ans += 1;
            s = e;
            e = s + L;
        }
    }

    cout << ans;

    return 0;
}