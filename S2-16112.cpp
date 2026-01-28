#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k;
vector<long long> vc;
long long ans;

int main() {
    cin >> n >> k;

    vc = vector<long long>(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    for (long long i = 1; i < n; i++) {
        long long tmp = vc[i] * min(i, k);
        ans += tmp;
    }

    cout << ans;

    return 0;
}