#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int t, n;
    map<string, int>::iterator it;
    string a, b;
    int ans;

    cin >> t;

    for (int i = 0; i < t; i++) {
        map<string, int> mp;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a >> b;
            mp[b] += 1;
        }

        ans = 1;

        for (it = mp.begin(); it != mp.end(); it++) {
            ans *= (it->second + 1);
        }

        cout << ans - 1 << "\n";
    }

    return 0;
}