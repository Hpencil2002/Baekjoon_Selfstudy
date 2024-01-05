#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int k = 0;
        if (s[i] == 'O') {
            continue;
        }
        else {
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {
                k += 1;
                if (k == n) {
                    k -= 1;
                    ans += 1;
                }
                i += 2;
            }
            k = 0;
        }
    }

    cout << ans << "\n";

    return 0;
}