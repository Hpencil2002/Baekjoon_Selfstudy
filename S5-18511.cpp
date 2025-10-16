#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, ans;
vector<int> vc;

void solve(int num) {
    if (N < num) {
        return;
    }

    ans = max(ans, num);
    num *= 10;

    for (int i = 0; i < K; i++) {
        solve(num + vc[i]);
    }
}

int main() {
    cin >> N >> K;

    vc = vector<int>(K);
    for (int i = 0; i < K; i++) {
        cin >> vc[i];
    }

    solve(0);

    cout << ans;

    return 0;
}