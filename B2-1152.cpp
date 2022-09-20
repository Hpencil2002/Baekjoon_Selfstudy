#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int cnt = 0;

    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            cnt += 1;
        }
    }

    if (s[0] == ' ') {
        cnt -= 1;
    }
    if (s[s.length() - 1] == ' ') {
        cnt -= 1;
    }

    cout << cnt + 1 << "\n";

    return 0;
}