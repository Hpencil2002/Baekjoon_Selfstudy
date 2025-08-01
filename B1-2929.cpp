#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        while (isupper(str[i]) && (i + ans) % 4 != 0) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}