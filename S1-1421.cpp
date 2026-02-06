#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, W;
vector<int> vc;
long long ans;

int main() {
    cin >> N >> C >> W;

    long long maxNum = 0;
    for (int i = 0; i < N; i++) {
        long long wood;
        cin >> wood;

        vc.push_back(wood);
        maxNum = max(maxNum, wood);
    }

    for (int i = 1; i <= maxNum; i++) {
        long long res = 0;

        for (int j = 0; j < N; j++) {
            if (i == vc[j]) {
                res += i * W;
            }
            else if (i < vc[j]) {
                int tmp = vc[j] % i == 0 ? -1 : 0;

                if (((vc[j] / i) + tmp) * C < (i * W) * (vc[j] / i)) {
                    res -= ((vc[j] / i) + tmp) * C;
                    res += (i * W) * (vc[j] / i);
                }
            }
        }

        ans = max(ans, res);
    }

    cout << ans;

    return 0;
}