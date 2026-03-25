#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string gear1, gear2;
int ans;

int main() {
    cin >> gear1 >> gear2;
    if (gear1.length() > gear2.length()) {
        swap(gear1, gear2);
    }

    ans = gear1.length() + gear2.length();

    for (int i = 0; i < gear1.length(); i++) {
        int len = gear1.length();
        bool flag = false;

        for (int j = 0; j <= i; j++) {
            if (gear2[j] == '2' && gear1[len - 1 - i + j] == '2') {
                flag = true;

                break;
            }
        }

        if (!flag) {
            ans = min(ans, (int)gear1.length() + (int)gear2.length() - 1 - i);
        }
    }
    for (int i = 0; i < gear1.length(); i++) {
        int len = gear2.length();
        bool flag = false;

        for (int j = 0; j <= i; j++) {
            if (gear2[len - 1 - i + j] == '2' && gear1[j] == '2') {
                flag = true;

                break;
            }
        }

        if (!flag) {
            ans = min(ans, (int)gear1.length() + (int)gear2.length() - 1 - i);
        }
    }

    for (int i = 0; i < gear2.length() - gear1.length(); i++) {
        bool flag = false;

        for (int j = 0; j < gear1.length(); j++) {
            if (gear1[j] == '2' && gear2[i + j] == '2') {
                flag = true;

                break;
            }
        }

        if (!flag) {
            ans = min(ans, (int)gear2.length());
        }
    }

    cout << ans;

    return 0;
}