#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long ans;
vector<pair<int, int>> vc;

int main() {
    cin >> n;
    vc = vector<pair<int, int>>(n);

    for (int i = 0; i < n; i++) {
        cin >> vc[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> vc[i].first;
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < n; i++) {
        ans += vc[i].second + vc[i].first * i;
    }

    cout << ans;

    return 0;
}