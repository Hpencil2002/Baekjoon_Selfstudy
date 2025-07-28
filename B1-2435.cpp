#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    vector<int> sums = vector<int>(N);
    for (int i = 0; i <= N - K; i++) {
        int num = vc[i];
        int k = K;

        for (int j = i + 1; k > 1; j++) {
            num += vc[j];
            k -= 1;
        }

        sums[i] = num;
    }

    int ans = -99999999;
    for (int i = 0; i <= N - K; i++) {
        ans = max(ans, sums[i]);
    }

    cout << ans;

    return 0;
}