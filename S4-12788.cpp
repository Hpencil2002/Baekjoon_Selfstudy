#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    int sum = M * K;

    sort(vc.begin(), vc.end());

    int ans = 0;
    while (!vc.empty()) {
        sum -= vc.back();
        vc.pop_back();
        ans += 1;

        if (sum <= 0) {
            cout << ans;

            return 0;
        }
    }

    cout << "STRESS";

    return 0;
}