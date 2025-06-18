#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 1000000000

int N, L, W, H;
long double ans = 0;

bool check(long double mid) {
    long long a = L / mid;
    long long b = W / mid;
    long long c = H / mid;

    long long cnt = a * b * c;

    if (cnt >= N) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cin >> N >> L >> W >> H;

    long double left = 0;
    long double right = min(L, min(W, H));
    int cnt = 0;
    while (left <= right) {
        if (cnt == 150) {
            break;
        }

        long double mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
            ans = mid;
        }
        else {
            right = mid;
        }
        cnt += 1;
    }

    cout.precision(30);
    cout << ans;

    return 0;
}