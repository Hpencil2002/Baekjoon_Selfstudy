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

    int M;
    cin >> M;

    int ans = 0, sum = 0;
    int left = 0;
    int right = vc[N - 1];
    while (left <= right) {
        sum = 0;
        int mid = (left + right) / 2;
        for (int i = 0; i < N; i++) {
            sum += min(vc[i], mid);
        }

        if (M >= sum) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}