#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int S, C;
long long sum, ans;
vector<int> vc;

bool check(long long mid) {
    long long cnt = 0;

    for (int i = 0; i < vc.size(); i++) {
        cnt += vc[i] / mid;
    }

    return cnt >= C;
}

int main() {
    cin >> S >> C;

    vc.resize(S, 0);
    for (int i = 0; i < S; i++) {
        cin >> vc[i];
        sum += vc[i];
    }

    long long left = 1;
    long long right = 1000000000;
    long long res = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;

        if (check(mid)) {
            left = mid + 1;
            res = mid;
        }
        else {
            right = mid - 1;
        }
    }
    ans = sum - res * C;

    cout << ans;

    return 0;
}