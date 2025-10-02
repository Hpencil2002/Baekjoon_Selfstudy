#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<string>> mp;

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string team;
        int cnt;
        cin >> team >> cnt;

        for (int j = 0; j < cnt; j++) {
            string name;
            cin >> name;
            mp[team].push_back(name);
        }
    }

    for (int i = 0; i < M; i++) {
        string str;
        int type;
        cin >> str >> type;

        if (type == 0) {
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->first.compare(str) == 0) {
                    sort(it->second.begin(), it->second.end());
                    for (string s : it->second) {
                        cout << s << "\n";
                    }
                }
            }
        }
        else if (type == 1) {
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (find(it->second.begin(), it->second.end(), str) != it->second.end()) {
                    cout << it->first << "\n";
                }
            }
        }
    }

    return 0;
}