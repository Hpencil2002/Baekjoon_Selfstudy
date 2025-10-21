#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int num;
        cin >> num;

        int ans = 0;
        while (num != 6174) {
            string str = to_string(num);
            while (str.length() != 4) {
                str = "0" + str;
            }
            sort(str.begin(), str.end());

            string str2 = str;
            reverse(str2.begin(), str2.end());

            num = abs(stoi(str2) - stoi(str));
            ans += 1;
        }

        cout << ans << "\n";
    }

    return 0;
}