#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    int ans = 1;
    for (int i = 0; i < N; i++) {
        int tmp = 1;

        for (int j = i + 1; j < i + 5; j++) {
            if (vc[j] - vc[i] < 5 && vc[j] - vc[i] > 0) {
                tmp += 1;
            }
        }

        ans = max(ans, tmp);
    }

    if (ans >= 5) {
        cout << 0;
    }
    else {
        cout << 5 - ans << "\n";
    }

    return 0;
}