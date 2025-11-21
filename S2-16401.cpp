#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    int ans = 0;
    int left = 1;
    int right = vc[N - 1];

    while (left <= right) {
        int mid = (left + right) / 2;

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += vc[i] / mid;
        }

        if (cnt < M) {
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