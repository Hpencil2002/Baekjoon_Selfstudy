#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num;
vector<int> A;

bool check(int mid) {
    if (A[mid] >= num) {
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < M; i++) {
        cin >> num;

        int left = 0;
        int right = A.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (check(mid)) {
                if (A[mid] == num) {
                    ans = mid;
                }

                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}