#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    int ans = 0;
    int tmp = vc[0];
    vector<bool> bvc = vector<bool>(N);
    while (bvc[tmp] != true) {
        ans += 1;
        bvc[tmp] = true;

        if (tmp == K) {
            cout << ans << "\n";

            return 0;
        }

        tmp = vc[tmp];
    }

    cout << "-1\n";

    return 0;
}