#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 1; i <= str.size(); i++) {
        if (str[i - 1] == 'N') {
            continue;
        }

        ans += 1;
        for (int j = i; j <= str.size(); j += i) {
            str[j - 1] = (str[j - 1] == 'N') ? 'Y' : 'N';
        }
    }

    cout << ans;

    return 0;
}