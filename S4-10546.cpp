#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        mp[name] += 1;
    }

    for (int i = 0; i < N - 1; i++) {
        string name;
        cin >> name;
        mp[name] -= 1;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second != 0) {
            cout << it->first;
            return 0;
        }
    }
}