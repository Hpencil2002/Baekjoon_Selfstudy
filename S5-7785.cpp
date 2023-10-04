#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string name, stat;
    map<string, string, greater<>> mp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> stat;
        mp[name] = stat;
    }

    map<string, string>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->second == "enter") {
            cout << it->first << "\n";
        }
    }

    return 0;
}