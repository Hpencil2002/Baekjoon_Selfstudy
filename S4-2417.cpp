#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans;
    ans = sqrt(n);

    if (ans * ans < n) {
        ans += 1;
    }

    cout << ans;

    return 0;
}