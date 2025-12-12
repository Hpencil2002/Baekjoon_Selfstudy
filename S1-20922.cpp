#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int ans = -1;
int visit[100002];

int main() {
    cin >> N >> K;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    int end = 0;
    for (int start = 0; start < N; start++) {
        while (end < N && visit[vc[end]] < K) {
            visit[vc[end]] += 1;
            end += 1;
        }

        ans = max(ans, end - start);

        if (end == N) {
            break;
        }
        visit[vc[start]] -= 1;
    }

    cout << ans;

    return 0;
}