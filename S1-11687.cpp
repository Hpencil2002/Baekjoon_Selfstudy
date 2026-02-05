#include <iostream>
using namespace std;

int M;
int ans;

int check(int x) {
    int res = 0;

    for (int i = 5; i < x + 1; i *= 5) {
        res += (x / i);
    }

    return res;
}

int main() {
    cin >> M;

    long long start = 1;
    long long end = INT32_MAX;
    while (start <= end) {
        int mid = (start + end) / 2;

        int c = check(mid);
        if (c >= M) {
            if (c == M) {
                ans = mid;
            }

            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    if (ans == 0) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}