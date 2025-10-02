#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int mul5 = 5;
        int sum = 0;
        while (mul5 <= N) {
            sum += N / mul5;
            mul5 *= 5;
        }

        cout << sum << "\n";
    }

    return 0;
}