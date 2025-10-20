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

    int ans = 0;
    int max_num = -1;
    for (int i = vc.size() - 1; i >= 0; i--) {
        if (vc[i] > max_num) {
            max_num = vc[i];
        }

        ans = max(ans, max_num - vc[i]);
    }

    cout << ans;

    return 0;
}