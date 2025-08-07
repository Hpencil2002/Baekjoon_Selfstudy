#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vc = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    int ans = 0;
    for (int i = 0; i < vc.size() - 1; i++) {
        ans += vc[i];
    }

    cout << ans;

    return 0;
}