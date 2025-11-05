#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    vector<int> sum = vector<int>(N + 1);
    sum[1] = vc[0];
    for (int i = 2; i <= N; i++) {
        sum[i] = sum[i - 1] + vc[i - 1];
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;

        cout << sum[R] - sum[L - 1] << "\n";
    }

    return 0;
}