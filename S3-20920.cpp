#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    else if (a.first.size() != b.first.size()) {
        return a.first.size() > b.first.size();
    }
    else {
        return a.first < b.first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string str;
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str.size() >= M) {
            mp[str] += 1;
        }
    }

    vector<pair<string, int>> vc(mp.begin(), mp.end());

    sort(vc.begin(), vc.end(), comp);

    for (auto &val : vc) {
        cout << val.first << "\n";
    }

    return 0;
}