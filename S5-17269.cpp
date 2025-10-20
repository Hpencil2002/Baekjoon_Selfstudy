#include <iostream>
#include <string>
#include <vector>
using namespace std;

int alp[26] = { 3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
vector<int> vc;

void solve(vector<int> vc) {
    if (vc.size() == 2) {
        int ans = 10 * vc[0] + vc[1];
        cout << ans << '%';

        return;
    }

    vector<int> vc2;
    for (int i = 1; i < vc.size(); i++) {
        vc2.push_back((vc[i] + vc[i - 1]) % 10);
    }

    solve(vc2);
}

int main() {
    int N, M;
    string A, B;
    cin >> N >> M >> A >> B;

    int max_len = N > M ? N : M;
    for (int i = 0; i < max_len; i++) {
        if (N > i) {
            vc.push_back(alp[A[i] - 'A']);
        }
        if (M > i) {
            vc.push_back(alp[B[i] - 'A']);
        }
    }

    solve(vc);

    return 0;
}