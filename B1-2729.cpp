#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        bitset<200> a, b;
        cin >> a >> b;

        bitset<200> c;
        int flag = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] + b[i] + flag == 3) {
                c[i] = 1;
                flag = 1;
            }
            else if (a[i] + b[i] + flag == 2) {
                c[i] = 0;
                flag = 1;
            }
            else if (a[i] + b[i] + flag == 1) {
                c[i] = 1;
                flag = 0;
            }
            else if (a[i] + b[i] + flag == 0) {
                c[i] = 0;
                flag = 0;
            }
        }

        string ans = "";
        flag = 0;

        for (int i = 199; i >= 0; i--) {
            if (c[i]) {
                flag = 1;
                ans += to_string(c[i]);
            }
            else if (flag) {
                ans += to_string(c[i]);
            }
        }

        if (ans == "") {
            cout << "0\n";
        }
        else {
            cout << ans << "\n";
        }
    }

    return 0;
}