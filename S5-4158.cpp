#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> ump;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0) {
            return 0;
        }

        ump.clear();
        for (int i = 0; i < N; i++) {
            int cd;
            cin >> cd;
            ump[cd] = 1;
        }

        int ans = 0;
        for (int i = 0; i < M; i++) {
            int cd;
            cin >> cd;
            if (ump[cd]) {
                ans += 1;
            }
        }

        cout << ans << "\n";
    }
}