#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string buf;
        getline(cin, buf);
        string origin;
        getline(cin, origin);

        map<string, bool> mp;
        while (true) {
            string a, b, c;
            cin >> a >> b >> c;

            if (a == "what") {
                cin >> b >> c;
                break;
            }

            mp[c] = true;
        }

        string ans = "";
        for (int i = 0; i < origin.size(); i++) {
            if (origin[i] == ' ') {
                if (!mp[ans]) {
                    cout << ans << ' ';
                }
                ans = "";
            }
            else {
                ans += origin[i];
            }
        }

        if (!mp[ans]) {
            cout << ans << ' ';
        }
        cout << "\n";
    }

    return 0;
}