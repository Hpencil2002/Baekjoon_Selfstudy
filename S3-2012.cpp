#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs((i + 1) - vc[i]);
    }

    cout << ans;

    return 0;
}