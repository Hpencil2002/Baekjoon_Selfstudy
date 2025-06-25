#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, search;
    int ans = 0;

    getline(cin, str);
    getline(cin, search);

    for (int i = 0; i < str.length(); i++) {
        bool check = true;

        for (int j = 0; j < search.length(); j++) {
            if (str[i + j] != search[j]) {
                check = false;
                break;
            }
        }

        if (check) {
            ans += 1;
            i += search.length() - 1;
        }
    }

    cout << ans;

    return 0;
}