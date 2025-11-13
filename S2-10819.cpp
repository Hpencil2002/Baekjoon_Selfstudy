#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    int ans = 0;
    int sum;
    while (next_permutation(vc.begin(), vc.end())) {
        sum = 0;
        for (int i = 0; i < vc.size() - 1; i++) {
            sum += abs(vc[i] - vc[i + 1]);
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}