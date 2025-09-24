#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> order;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return order[a.first] < order[b.first];
    }

    return a.second > b.second;
}

int main() {
    int N, C;
    cin >> N >> C;

    map<int, int> mp;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        mp[num] += 1;

        if (order[num] == 0) {
            order[num] = i + 1;
        }
    }

    vector<pair<int, int>> vc = vector<pair<int, int>>(mp.begin(), mp.end());

    sort(vc.begin(), vc.end(), cmp);

    for (auto x : vc) {
        for (int i = 0; i < x.second; i++) {
            cout << x.first << ' ';
        }
    }

    return 0;
}