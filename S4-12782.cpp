#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string N, M;
        cin >> N >> M;

        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < N.size(); i++) {
            if (N[i] != M[i]) {
                if (N[i] == '0') {
                    cnt0 += 1;
                }
                else {
                    cnt1 += 1;
                }
            }
        }

        cout << ((cnt0 > cnt1) ? cnt0 : cnt1) << "\n";
    }

    return 0;
}