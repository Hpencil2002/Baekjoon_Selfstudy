#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string S, E, Q;
string T, name;
int ans;
unordered_map<string, int> mp;

int main() {
    cin >> S >> E >> Q;

    while (cin >> T >> name) {
        if (T <= S) {
            mp[name] = 1;
        }
        else if (T >= E && T <= Q) {
            if (mp[name] == 1) {
                mp[name] = 2;
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}