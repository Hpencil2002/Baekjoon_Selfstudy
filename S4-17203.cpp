#include <iostream>
#include <cmath>
using namespace std;

int N, Q;
long long arr[1001];
long long ans[1001];

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ans[i] = ans[i - 1] + abs(arr[i] - arr[i - 1]);
    }

    while (Q--) {
        int s, e;
        cin >> s >> e;

        if ((e - 1) < s) {
            cout << "0\n";
        }
        else {
            cout << ans[e] - ans[s] << "\n";
        }
    }

    return 0;
}