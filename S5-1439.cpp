#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int ans = 0;

    cin >> str;
    char now = str[0];
    for (int i = 1; i < str.size(); i++) {
        if (now != str[i]) {
            ans += 1;
            now = str[i];
        }
    }

    if (ans % 2 == 1) {
        ans /= 2;
        ans += 1;
    }
    else {
        ans /= 2;
    }

    cout << ans;

    return 0;
}