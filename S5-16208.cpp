#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> vc = vector<long long>(n);
    long long len = 0;
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
        len += vc[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += vc[i] * (len - vc[i]);
        len -= vc[i];
    }

    cout << ans;

    return 0;
}