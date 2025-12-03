#include <iostream>
#include <string>
using namespace std;

string s, p;
int ans;

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> s >> p;
        ans = 0;

        for (int i = 0; i < s.size(); i++) {
            string tmp = "";
            if (i + p.size() <= s.size()) {
                for (int j = i; j < i + p.size(); j++) {
                    tmp += s[j];
                }

                if (tmp == p) {
                    ans += 1;
                    i += p.size() - 1;
                }
                else {
                    ans += 1;
                }
            }
            else {
                ans += 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}