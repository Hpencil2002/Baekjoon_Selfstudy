#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> vc = vector<int>(N);
        for (int i = 0; i < N; i++) {
            cin >> vc[i];
        }

        int ans = vc[0];
        int tmp;
        vector<int> res;
        res.push_back(vc[0]);

        for (int i = 1; i < N; i++) {
            if (vc[i] + res[i - 1] >= vc[i]) {
                tmp = vc[i] + res[i - 1];
            }
            else {
                tmp = vc[i];
            }

            res.push_back(tmp);
            if (ans < tmp) {
                ans = tmp;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}