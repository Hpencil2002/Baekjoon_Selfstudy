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

    sort(vc.begin(), vc.end());

    int ans = 0;
    int cnt = N - 1;
    for (int i = 0; i < K; i++) {
        ans += (vc[cnt--] - i);
    }

    cout << ans;

    return 0;
}