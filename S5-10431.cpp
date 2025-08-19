#include <iostream>
using namespace std;

int main() {
    int P;
    cin >> P;

    while (P--) {
        int T;
        cin >> T;

        int student[20];
        for (int i = 0; i < 20; i++) {
            cin >> student[i];
        }

        int ans = 0;
        for (int i = 0; i < 20; i++) {
            for (int j = i; j < 20; j++) {
                if (student[i] > student[j]) {
                    ans += 1;
                }
            }
        }

        cout << T << ' ' << ans << "\n";
    }

    return 0;
}