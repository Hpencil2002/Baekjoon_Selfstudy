#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> vc;
int parent[10001];
int ans = 0;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);

    parent[y] = x;
}

bool sameParent(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        vc.push_back({ C, { A, B } });
    }

    sort(vc.begin(), vc.end());
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < vc.size(); i++) {
        if (!sameParent(vc[i].second.first, vc[i].second.second)) {
            uni(vc[i].second.first, vc[i].second.second);

            ans += vc[i].first;
        }
    }

    cout << ans;

    return 0;
}