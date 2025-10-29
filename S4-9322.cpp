#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        unordered_map<string, int> ump;
        vector<int> arr = vector<int>(n);
        vector<string> vc = vector<string>(n);
        for (int i = 0; i < n; i++) {
            cin >> vc[i];
            ump[vc[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;

            arr[i] = ump[str];
        }

        vector<string> ans = vector<string>(n);
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;

            ans[arr[i]] = str;
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << "\n";
    }

    return 0;
}