#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int ans = 1e9;
int arr[1000004];
vector<int> vc;

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        if (x == 1) {
            vc.push_back(i);
        }
    }

    if (vc.size() < K) {
        cout << -1;

        return 0;
    }

    int start = 0;
    int end = K - 1;
    for (int i = 0; i <= vc.size() - K; i++) {
        ans = min(ans, vc[end] - vc[start] + 1);
        end += 1;
        start += 1;
    }

    cout << ans;

    return 0;
}