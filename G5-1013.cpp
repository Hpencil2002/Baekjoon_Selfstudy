#include <iostream>
#include <string>
#include <regex>
using namespace std;

string str;
regex pattern("(100+1+|01)+");

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> str;
        cout << (regex_match(str, pattern) ? "YES\n" : "NO\n");
    }

    return 0;
}