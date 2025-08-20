#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    char d;
    cin >> n >> d;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string tmp = to_string(i);

        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] == d) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}