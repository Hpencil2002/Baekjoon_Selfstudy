#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> mp;

int main() {
    string name;
    int cnt = 0;

    while (getline(cin, name)) {
        mp[name] += 1;
        cnt += 1;
    }

    cout << fixed;
    cout.precision(4);
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << ' ' << (double)it->second / cnt * 100 << "\n";
    }

    return 0;
}