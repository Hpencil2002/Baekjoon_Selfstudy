#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T;
string str;

int main() {
    cin >> T;

    while (T--) {
        cin >> str;

        if (!next_permutation(str.begin(), str.end())) {
            prev_permutation(str.begin(), str.end());
        }

        for (auto c : str) {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}