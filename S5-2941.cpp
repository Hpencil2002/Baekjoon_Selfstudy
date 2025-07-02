#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (i + 1 < str.size() && str[i] == 'c' && str[i + 1] == '=') {
            ans += 1;
            i += 1;
        }
        else if (i + 1 < str.size() && str[i] == 'c' && str[i + 1] == '-') {
            ans += 1;
            i += 1;
        }
        else if (i + 1 < str.size() && i + 2 < str.size() && str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
            ans += 1;
            i += 2;
        }
        else if (i + 1 < str.size() && str[i] == 'd' && str[i + 1] == '-') {
            ans += 1;
            i += 1;
        }
        else if (i + 1 < str.size() && str[i] == 'l' && str[i + 1] == 'j') {
            ans += 1;
            i += 1;
        }
        else if (i + 1 < str.size() && str[i] == 'n' && str[i + 1] == 'j') {
            ans += 1;
            i += 1;
        }
        else if (i + 1 < str.size() && str[i] == 's' && str[i + 1] == '=') {
            ans += 1;
            i += 1;
        }
        else if (i + 1 < str.size() && str[i] == 'z' && str[i + 1] == '=') {
            ans += 1;
            i += 1;
        }
        else {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}