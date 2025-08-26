#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    map<string, bool> mp;
    while (N--) {
        string A, B;
        cin >> A >> B;

        if (A == "ChongChong") {
            mp.insert({A, true});
        }
        else if (B == "ChongChong") {
            mp.insert({B, true});
        }

        if (mp[A]) {
            mp[B] = true;
        }
        if (mp[B]) {
            mp[A] = true;
        }
    }

    for (auto& val : mp) {
        if (val.second) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}