#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main() {
    int n, x, y;
    vector<pair<int, int>> vc;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vc.push_back(make_pair(x, y));
    }

    sort(vc.begin(), vc.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << vc[i].first << " " << vc[i].second << "\n";
    }

    return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}