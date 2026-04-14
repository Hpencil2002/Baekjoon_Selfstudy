#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int ans = 0;
        int pos[1001];
        int dest[1001];
        for (int i = 1; i <= N; i++) {
            cin >> dest[i];
            pos[i] = i;
        }

        for (int i = 1; i <= N; i++) {
            int index = find(pos, pos + N + 1, dest[i]) - pos;

            for (int j = index; j > i; j--) {
                swap(pos[j], pos[j - 1]);
                ans += 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}