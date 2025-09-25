#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    int N;
    cin >> N;

    string pattern;
    cin >> pattern;

    string reg;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == '*') {
            reg += ".*";
        }
        else {
            reg += pattern[i];
        }
    }

    regex e(reg);
    while (N--) {
        string name;
        cin >> name;

        regex_match(name, e) ? cout << "DA\n" : cout << "NE\n";
    }

    return 0;
}