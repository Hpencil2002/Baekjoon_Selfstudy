#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string str;
        getline(cin, str);

        int dep = 0;
        int ans = 0;
        for (auto c : str) {
            dep += (c == '[' ? 1 : -1);
            ans = max(ans, dep);
        }

        cout << (1 << ans) << "\n";
    }

    return 0;
}