#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

vector<int> x;
vector<int> y;

int calc(int i, int j, int k) {
    int res = 0;

    for (int h = 0; h < N; h++) {
        res = max(res, min(min(abs(x[i] - x[h]) + abs(y[i] - y[h]), abs(x[j] - x[h]) + abs(y[j] - y[h])), abs(x[k] - x[h]) + abs(y[k] - y[h])));
    }

    return res;
}

int main() {
    int ans = 1e9;
    cin >> N >> K;

    x = vector<int>(N);
    y = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            ans = min(ans, calc(i, i, i));
        }
    }
    else if (K == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans = min(ans, calc(i, j, j));
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    ans = min(ans, calc(i, j, k));
                }
            }
        }
    }

    cout << ans;

    return 0;
}