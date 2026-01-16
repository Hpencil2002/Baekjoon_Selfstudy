#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vc, sorted;
int ans;

int main() {
    cin >> N;

    vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sorted = vector<int>(N);
    copy(vc.begin(), vc.end(), sorted.begin());

    sort(sorted.begin(), sorted.end());

    ans = N;
    int cur = N - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (vc[i] == sorted[cur]) {
            ans -= 1;
            cur -= 1;
        }
    }

    cout << ans;

    return 0;
}