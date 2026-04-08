#include <iostream>
#include <vector>
using namespace std;

int n, k;
int ans;
vector<int> vc[100001];
int arr[100001];

void dfs(int node, int dist) {
    if (dist > k) {
        return;
    }

    ans += arr[node];
    for (int i = 0; i < vc[node].size(); i++) {
        dfs(vc[node][i], dist + 1);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;

        vc[p].push_back(c);
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}