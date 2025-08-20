#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, bool> mp;
int N, M;
string str;
int ans = 0;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> str;
        mp.insert(pair<string, bool>(str, true));
    }

    for (int i = 0; i < M; i++) {
        cin >> str;

        if (mp[str] == true) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}