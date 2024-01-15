#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = 0;
    int *peo;
    cin >> n;
    peo = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> peo[i];
    }

    sort(peo, peo + n);

    for (int i = 0; i < n; i++) {
        ans += peo[i] * (n - i);
    }

    cout << ans;

    return 0;
}