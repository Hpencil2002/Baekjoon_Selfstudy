#include <iostream>
#include <vector>
using namespace std;

int N, K, M;
vector<int> vc;
int ans = -1;

int main() {
    cin >> N >> K >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a <= K) {
            a = 0;
        }
        else if (a < 2 * K) {
            a -= K;
        }
        else {
            a -= 2 * K;
        }
        vc.push_back(a);
    }

    int left = 1;
    int right = 1000000000;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            cnt += vc[i] / mid;
        }

        if (M > cnt) {
            right = mid - 1;
        }
        else {
            ans = mid;
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}