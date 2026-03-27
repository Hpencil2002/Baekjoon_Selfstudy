#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans;
vector<pair<int, pair<int, int>>> edge;
int parent[100001];
vector<int> vc;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

void uni(int x, int y, int cost) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }

    parent[y] = x;
    N -= 1;
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
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        edge.push_back({ C, { A, B }});
    }

    sort(edge.begin(), edge.end());
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edge.size(); i++) {
        if (!sameParent(edge[i].second.first, edge[i].second.second)) {
            uni(edge[i].second.first, edge[i].second.second, edge[i].first);

            vc.push_back(edge[i].first);
        }
    }

    for (int i = 0; i < vc.size() - 1; i++) {
        ans += vc[i];
    }

    cout << ans;

    return 0;
}