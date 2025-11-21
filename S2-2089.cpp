#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    string ans;
    if (!N) {
        ans = "0";
    }
    else {
        while (N) {
            if (!(N % -2)) {
                ans += "0";
                N /= -2;
            }
            else {
                ans += "1";
                N = (N - 1) / -2;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}