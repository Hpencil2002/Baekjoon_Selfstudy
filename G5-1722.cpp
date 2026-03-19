#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, t;
long long k;
long long fac[21];

int main() {
    cin >> N;

    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i;
    }

    cin >> t;
    if (t == 1) {
        cin >> k;
        vector<int> ans = vector<int>(N + 1, 0);
        vector<bool> visit = vector<bool>(N + 1, false);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (visit[j]) {
                    continue;
                }

                if (fac[N - i] < k) {
                    k -= fac[N - i];
                }
                else {
                    ans[i] = j;
                    visit[j] = true;

                    break;
                }
            }
        }

        for (int i = 1; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
    }
    else if (t == 2) {
        vector<int> perm = vector<int>(N + 1, 0);
        vector<bool> visit = vector<bool>(N + 1, false);

        for (int i = 1; i <= N; i++) {
            cin >> perm[i];
        }

        long long ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < perm[i]; j++) {
                if (!visit[j]) {
                    ans += fac[N - i];
                }
            }

            visit[perm[i]] = true;
        }

        cout << ans + 1;
    }

    return 0;
}