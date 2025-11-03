#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M;
    cin >> M;

    vector<int> num = vector<int>(M);
    int total = 0;
    for (int i = 0; i < M; i++) {
        cin >> num[i];
        total += num[i];
    }

    int K;
    cin >> K;

    double ans = 0;
    for (int i = 0; i < M; i++) {
        double tmp = 1.0;

        if (K > num[i]) {
            continue;
        }

        for (int j = 0; j < K; j++) {
            tmp *= (double)(num[i] - j) / (total - j);
        }
        ans += tmp;
    }

    cout << fixed;
    cout.precision(15);
    cout << ans;

    return 0;
}