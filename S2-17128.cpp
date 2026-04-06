#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<int> cow;
vector<int> num;
vector<long long> sum;
long long ans;

int main() {
    cin >> N >> Q;

    cow = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> cow[i];
    }
    num = vector<int>(Q);
    for (int i = 0; i < Q; i++) {
        cin >> num[i];
    }

    sum = vector<long long>(N);
    for (int i = 0; i < N; i++) {
        long long v = 1;
        for (int j = i; j < i + 4; j++) {
            v *= cow[j % cow.size()];
        }

        sum[i] = v;
        ans += sum[i];
    }

    for (int i = 0; i < num.size(); i++) {
        int k = num[i] - 1;

        for (int j = k; j > k - 4; j--) {
            if (j < 0) {
                ans -= sum[cow.size() + j];
                sum[cow.size() + j] *= -1;
                ans += sum[cow.size() + j];
            }
            else {
                ans -= sum[j];
                sum[j] *= -1;
                ans += sum[j];
            }
        }

        cout << ans << "\n";
    }

    return 0;
}