#include <iostream>
#include <vector>
using namespace std;

int N, K;
long long ans;

int main() {
    cin >> N >> K;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    int left = 0;
    long long right = INT32_MAX;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long res = 0;

        for (int i = 0; i < N; i++) {
            res += vc[i] / mid;
        }

        if (res < K) {
            right = mid - 1;
        }
        else {
            ans = mid;
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}