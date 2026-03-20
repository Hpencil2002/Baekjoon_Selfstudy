#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

string N;
vector<string> ans;

bool solve(string str, int s, int f) {
    if (s >= f) {
        return true;
    }

    int left = s;
    int right = f;
    while (left < right) {
        if (str[left] != str[right]) {
            left += 1;
            right -= 1;
        }
        else {
            return false;
        }
    }

    return solve(str, s, right - 1);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N;
        if (N.length() == 1) {
            cout << "YES\n";

            continue;
        }

        if (solve(N, 0, N.length() - 1)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}