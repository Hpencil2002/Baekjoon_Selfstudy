#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K, B;
    cin >> N >> K >> B;

    vector<int> vc = vector<int>(N, 0);
    for (int i = 0; i < B; i++) {
        int tmp;
        cin >> tmp;
        vc[tmp - 1] = 1;
    }

    int ans = INT32_MAX;
    for (int i = 0; i < N - K + 1; i++) {
        int tmp = 0;
        for (int j = i; j < i + K; j++) {
            tmp += vc[j];
        }

        ans = min(ans, tmp);
    }

    cout << ans;

    return 0;
}