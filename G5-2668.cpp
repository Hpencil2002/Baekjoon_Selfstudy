#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int arr[101];
bool visit[101];
vector<int> ans;

void dfs(int cur, int start) {
    if (visit[cur]) {
        if (start == cur) {
            ans.push_back(cur);
        }

        return;
    }

    visit[cur] = true;
    dfs(arr[cur], start);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        dfs(i, i);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}