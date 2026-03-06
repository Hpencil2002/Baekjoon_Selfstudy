#include <iostream>
#include <string>
using namespace std;

int solve(int left, int right, int del, string str) {
    while (left < right) {
        if (str[left] != str[right]) {
            if (del == 0) {
                if (solve(left + 1, right, 1, str) == 0 || solve(left, right - 1, 1, str) == 0) {
                    return 1;
                }

                return 2;
            }
            else {
                return 2;
            }
        }
        else {
            left += 1;
            right -= 1;
        }
    }

    return 0;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;

        cout << solve(0, str.length() - 1, 0, str) << "\n";
    }

    return 0;
}