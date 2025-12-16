#include <iostream>
#include <string>
using namespace std;

string L, R;
int ans;

int main() {
    cin >> L >> R;

    if (L.size() != R.size()) {
        cout << 0;
    }
    else {
        for (int i = 0; i < L.size(); i++) {
            if (L[i] != R[i]) {
                break;
            }

            if (L[i] == R[i] && L[i] == '8') {
                ans += 1;
            }
        }

        cout << ans;
    }

    return 0;
}