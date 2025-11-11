#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    long long sum = 0;
    long long xor_ans = 0;
    while (M--) {
        int fi, se;
        cin >> fi;

        if (fi == 1) {
            cin >> se;

            sum += se;
            xor_ans ^= se;
        }
        else if (fi == 2) {
            cin >> se;

            sum -= se;
            xor_ans ^= se;
        }
        else if (fi == 3) {
            cout << sum << "\n";
        }
        else if (fi == 4) {
            cout << xor_ans << "\n";
        }
    }

    return 0;
}