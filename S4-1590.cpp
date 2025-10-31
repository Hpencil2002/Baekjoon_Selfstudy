#include <iostream>
#include <algorithm>
using namespace std;

int N, T;
int S, I, C;

bool check(int mid) {
    if (S + I * (mid - 1) >= T) {
        return true;
    }

    return false;
}

int main() {
    cin >> N >> T;

    int ans = -1;
    int tmp = 987654321;
    for (int i = 0; i < N; i++) {
        cin >> S >> I >> C;

        int left = 1;
        int right = C;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (check(mid)) {
                ans = (S + I * (mid - 1)) - T;
                ans = min(tmp, ans);
                tmp = ans;

                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }

    cout << ans;

    return 0;
}