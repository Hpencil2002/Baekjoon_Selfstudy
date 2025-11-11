#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    regex rg(R"(^[A-F]?A+F+C+[A-F]?$)");
    while (T--) {
        string str;
        cin >> str;

        if (regex_match(str, rg)) {
            cout << "Infected!\n";
        }
        else {
            cout << "Good\n";
        }
    }

    return 0;
}