#include <iostream>
#include <string>
using namespace std;

int B;
string D;
int ans;

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> B >> D;

        ans = 0;
        for (auto &s : D) {
            ans += s - '0';
        }

        cout << ans % (B - 1) << "\n";
    }

    return 0;
}