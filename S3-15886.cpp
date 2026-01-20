#include <iostream>
#include <string>
using namespace std;

int N;
string mp;
int ans;

int main() {
    cin >> N >> mp;

    for (int i = 0; i < N - 1; i++) {
        if (mp[i] == 'E' && mp[i + 1] == 'W') {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}