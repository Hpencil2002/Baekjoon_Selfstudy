#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> vc = vector<long long>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    long long ans = 0;
    if (N % 2 == 1) {
        ans = vc[N - 1];
        N -= 1;

        for (int i = 0; i < N / 2; i++) {
            long long sum = vc[i] + vc[(N - 1) - i];

            if (sum > ans) {
                ans = sum;
            }
        }
    }
    else {
        for (int i = 0; i < N / 2; i++) {
            long long sum = vc[i] + vc[(N - 1) - i];

            if (sum > ans) {
                ans = sum;
            }
        }
    }

    cout << ans;

    return 0;
}