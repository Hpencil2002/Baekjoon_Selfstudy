#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main() {
    int x, y, n;
    vector<pair<int, int>> point;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }

    sort(point.begin(), point.end(), compare);

    for (int i = 0; i < point.size(); i++) {
        cout << point[i].first << " " << point[i].second << "\n";
    }

    return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}