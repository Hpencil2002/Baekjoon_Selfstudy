#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    vector<int> v(N, 0);
    vector<int> c(10, 0);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int left = 0, right = 0;
    while (right < N) {
        c[v[right++]] += 1;

        while(10 - count(c.begin(), c.end(), 0) > 2) {
            c[v[left++]] -= 1;
        }

        ans = max(ans, right - left);
    }

    cout << ans;

    return 0;
}