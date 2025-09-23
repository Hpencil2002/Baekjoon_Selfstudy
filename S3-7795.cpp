#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A = vector<int>(N);
        vector<int> B = vector<int>(M);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int left = 0;
            int right = M;

            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (A[i] > B[mid]) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }

            ans += left;
            if (A[i] > B[left]) {
                ans += 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}