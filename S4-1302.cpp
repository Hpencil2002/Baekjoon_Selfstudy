#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N, cnt = 0;
    string title, tmp;
    map<string, int> mp;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> title;
        
        if (mp.find(title) != mp.end()) {
            mp[title] += 1;
        }
        else {
            mp[title] = 1;
        }
    }

    for (auto i : mp) {
        if (i.second > cnt) {
            tmp = i.first;
            cnt = i.second;
        }
    }

    cout << tmp;

    return 0;
}